#include "Minhook.h"
#include "FunctionImports.h"
#include "Windows.h"
#include <stdio.h>

#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"
#include <d3d11.h>

#include "D3D11Display.h"

#pragma once

IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//Has all hooks and MH intialization
namespace Hooks
{
	_SetUserControlActor pSetUserControlActor = NULL;
	_OnSwap pOnSwap = NULL;
	_Release pRelease = NULL;
	_onEndFrame ponEndFrame = NULL;
	_WindowProcedure pWindowProcedure = NULL;

	bool g_isGUIInitialized = false;
	bool g_showMenu = false;
	bool g_forceCursor = false;

	void hkOnSelectPlayerChangeMenu(uintptr_t PlayerChangeManager, int index)
	{
		MessageBoxW(NULL, L"hmm", L"ok", MB_OK);
		FunctionImports::fnOnSelectPlayerChangeMenu(PlayerChangeManager, index);
	}

	void* hkGetActorFromIndex(uintptr_t ActorTypeManager, int index)
	{
		MessageBoxW(NULL, L"GetActorFromIndex", (LPCWSTR)index, MB_OK);
		//return FunctionImports::fnGetActorFromIndex(ActorTypeManager, index);
		return NULL;
	}

	void hkSetUserControlActor(ActorManager* ActorManager, void* actor, bool bChangePadType, bool bDebugPad, bool bSave)
	{
		MessageBoxW(NULL, L"SetUserControlActor", (LPCWSTR)pSetUserControlActor, MB_OK);
		pSetUserControlActor(ActorManager, actor, bChangePadType, bDebugPad, bSave);
	}

	void DisplayOffsetButton(__int64 fnOffset, const char name[])
	{
		char offCursorText[50];
		sprintf(offCursorText, "0x%p", fnOffset);

		//Button text acts as its ID, so you can not have multiple buttons of identical names
		//You can append ## with additional text to have a different label that isn't displayed in rendering
		char buttonText[50];
		sprintf(buttonText, "Copy%s%p", "##", fnOffset);

		ImGui::InputText(name, offCursorText, sizeof(offCursorText), ImGuiInputTextFlags_ReadOnly);
		ImGui::SameLine();

		if (ImGui::Button(buttonText))
		{
			ImGui::SetClipboardText(offCursorText);
		}
		ImGui::SameLine();

		ImGui::NewLine();
	}

	void ShowGuiButton()
	{
		ImGui::Begin("Offsets");
		DisplayOffsetButton((__int64)FunctionImports::fnSetMouseCursorVisible, "SetMouseCursorVisible");
		DisplayOffsetButton((__int64)FunctionImports::fnSetController, "SetController");
		ImGui::End();
	}

	//D3D11::Present() equivalent
	//This is where ImGui initialization needs to exist - all other ImGui code can exist anywhere
	void hkonEndFrame(D3D11Display* display, ID3D11DeviceContext* context)
	{
		ID3D11Device* g_pd3dDevice = FunctionImports::fnGetD3DDevice();
		ID3D11RenderTargetView* g_pmainTargetView = display->surface.renderTargetView_;

		bool open = true;

		HWND hwnd = FindWindow(0, L"FINAL FANTASY XV WINDOWS EDITION (build 1138403)");

		if (!g_isGUIInitialized)
		{
			IMGUI_CHECKVERSION();
			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO(); (void)io;

			ImGui::StyleColorsDark();

			ImGui_ImplWin32_Init(hwnd);
			ImGui_ImplDX11_Init(g_pd3dDevice, context);

			g_isGUIInitialized = true;
		}

		// Start the Dear ImGui frame

		if (g_showMenu)
		{
			ImGui_ImplDX11_NewFrame();
			ImGui_ImplWin32_NewFrame();
			ImGui::NewFrame();

			ShowGuiButton();

			//TODO move main window to its own function
			ImGui::Begin("FFXV Local Co-op Debug Info");
			ImGui::SetWindowSize(ImVec2(400.00f, 400.00f));
			ImGui::Text("Test");
			
			if (ImGui::BeginMenu("Help"))
			{
				if (ImGui::MenuItem("Info"))
				{
					ImGui::Text("hi");
				}
				ImGui::EndMenu();
			}

			ImGui::End();

			ImGui::Render();
			context->OMSetRenderTargets(1, &g_pmainTargetView, NULL);
			ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		}

		ponEndFrame(display, context);
	}

	//This hook routes input to the ImGui window
	//TODO automatically handle mouse cursor visibility, disable game control
	__int64 hkWindowProcedure(HWND__ *hWnd, unsigned int msg, WPARAM wParam, LPARAM lParam)
	{
		ImGuiIO& io = ImGui::GetIO();
		POINT mPos;
		GetCursorPos(&mPos);
		ScreenToClient(hWnd, &mPos);
		ImGui::GetIO().MousePos.x = mPos.x;
		ImGui::GetIO().MousePos.y = mPos.y;

		if (msg == WM_KEYUP)
		{
			if (wParam == VK_DELETE)
			{
				//Enable
				if (!g_showMenu)
				{
					FunctionImports::fnSetMouseCursorVisible(true);
					g_showMenu = true;
				}
				
				//Disable
				else if (g_showMenu)
				{
					FunctionImports::fnSetMouseCursorVisible(false);
					g_showMenu = false;
				}
			}
		}

		if (g_showMenu)
		{
			ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam);
			return true;
		}

		return pWindowProcedure(hWnd, msg, wParam, lParam);
	}


	//returns -1 if any hooks fail
	int InitHooks()
	{
		MH_Initialize();

		//Hook Creation
		MH_CreateHook(FunctionImports::fnSetUserControlActor, &hkSetUserControlActor, reinterpret_cast<LPVOID*>(&pSetUserControlActor));
		MH_CreateHook(FunctionImports::fnonEndFrame, &hkonEndFrame, reinterpret_cast<LPVOID*>(&ponEndFrame));
		MH_CreateHook(FunctionImports::fnWindowProcedure, &hkWindowProcedure, reinterpret_cast<LPVOID*>(&pWindowProcedure));
		//MH_CreateHook(FunctionImports::fnSetMouseCursorVisible, &hkSetMouseCursorVisible, reinterpret_cast<LPVOID*>(&pSetMouseCursorVisible));

		//Activation
		if (MH_EnableHook(FunctionImports::fnSetUserControlActor) != MH_OK)
		{
			return -1;
		}

		if (MH_EnableHook(FunctionImports::fnonEndFrame) != MH_OK)
		{
			return -1;
		}

		if (MH_EnableHook(FunctionImports::fnWindowProcedure) != MH_OK)
		{
			return -1;
		}

		return 0;
	}

}