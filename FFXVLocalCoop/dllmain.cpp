#include "stdafx.h"
#include <iostream>

#include "FunctionImports.h"
#include "FunctionHooks.h"
#include <Minhook.h>

#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"
#include <d3d11.h>

#include "ActorManager.h"

FARPROC p[1] = { 0 }; //original d3d11 dll
bool initLocalCoop = true; //true when the game has loaded to the main menu

typedef int (WINAPI *MESSAGEBOXW)(HWND, LPCWSTR, LPCWSTR, UINT);

int WINAPI DetourMessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
	//return ogMessageBoxW(hWnd, L"Hello!", L"got hooked homie", uType);
	return MessageBoxW(hWnd, L"Seeya!", L"GONE", uType);
}


int MainLoop()
{
	bool doThings = true;
	//Was used before ImGui implementation, probably won't be enabled again
	/*
	FILE *f = fopen("C:\\Users\\xxk_.LINK\\Desktop\\FFXVDebugoutput.txt", "w+");
	if (!f)
	{
		MessageBox(NULL, L"Error", L"File failed to create", MB_OK);
		return -1;
	}
	fprintf(f, "Address: %p\n", &FunctionImports::fnGetActorFromIndex);
	fflush(f);
	*/



	// Probably:
	//  set pActorControllerComponent
	//  set CONTROLLER_TYPE
	//
	// Maybe:
	//  set actorAnimatedModelData
	//  set parkourComponent
	// FROM SetUserControllerActor

	// See:
	//	ActorControllerComponent::SetController(CONTROLLER_TYPE, ...)
	//	ActorControllerComponent::ActorControllerComponent(OwnerActor*) -- spawn own actor with own controller component?

	if (Hooks::InitHooks() == -1)
	{
		MessageBoxW(NULL, L"FAILURE", L"Hooks failed to init!", MB_OK);
		return -1;
	}

	/*
	ActorManager actorManager = FunctionImports::fnGetActorManagerInstance();
	ActorCharacter* player1 = (ActorCharacter*)&actorManager.partyActor_[0].handle_.ptr_.pointer_;
	void* actorControl1 = &player1->ActorControl;
	FunctionImports::fnSetUserControlStatus(actorControl1, CATEGORY_BIND, true);
	*/
	
	/*
	ActorManager actorManager = FunctionImports::fnGetActorManagerInstance();
	Actor* actor1 = FunctionImports::fnGetBuddyActor(0);
	Actor* actor2 = FunctionImports::fnGetBuddyActor(1);

	Individuality* actor1Individuality = FunctionImports::fnGetIndividuality(actor1);
	Individuality* actor2Individuality = FunctionImports::fnGetIndividuality(actor2);
	
	ActorControllerComponent* firstActorController = actor1Individuality->pIController_;

	PlayerChangeManager* playerChangeManager = FunctionImports::fnGetPlayerChangeManager();
	*/

	while (true)
	{
		if (GetAsyncKeyState(VK_INSERT))
		{
			MessageBoxW(NULL, L"END", L"END", MB_OK);
		}		
	}
}

extern "C" HRESULT Proxy_D3D11CreateDevice(
	IDXGIAdapter            *pAdapter,
	D3D_DRIVER_TYPE         DriverType,
	HMODULE                 Software,
	UINT                    Flags,
	const D3D_FEATURE_LEVEL *pFeatureLevels,
	UINT                    FeatureLevels,
	UINT                    SDKVersion,
	ID3D11Device            **ppDevice,
	D3D_FEATURE_LEVEL       *pFeatureLevel,
	ID3D11DeviceContext     **ppImmediateContext)
{
	if (initLocalCoop)
	{
		CreateThread(NULL, 0, (unsigned long(__stdcall*)(void*))MainLoop, NULL, 0, NULL);
		initLocalCoop = false;
	}

	typedef long(__stdcall *pS)(
		IDXGIAdapter            *pAdapter,
		D3D_DRIVER_TYPE         DriverType,
		HMODULE                 Software,
		UINT                    Flags,
		const D3D_FEATURE_LEVEL *pFeatureLevels,
		UINT                    FeatureLevels,
		UINT                    SDKVersion,
		ID3D11Device            **ppDevice,
		D3D_FEATURE_LEVEL       *pFeatureLevel,
		ID3D11DeviceContext     **ppImmediateContext);
	pS pps = (pS)p[0 * 4];
	long rv = pps(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, ppDevice, pFeatureLevel, ppImmediateContext);
	return rv;
}

extern "C" BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	static HINSTANCE hL;
	if (reason == DLL_PROCESS_ATTACH)
	{
		hL = LoadLibrary(L".\\d3d11_org.dll");
		if (!hL) return false;
		p[0] = GetProcAddress(hL, "D3D11CreateDevice");
		//CreateThread(NULL, 0, (unsigned long(__stdcall*)(void*))MainLoop, NULL, 0, NULL);
	}
	if (reason == DLL_PROCESS_DETACH)
		FreeLibrary(hL);
	return TRUE;
}