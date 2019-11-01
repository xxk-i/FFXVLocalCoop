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

	if (Hooks::InitHooks() == -1)
	{
		MessageBoxW(NULL, L"FAILURE", L"Hooks failed to init!", MB_OK);
		return -1;
	}
	
	while (true)
	{
		if (GetAsyncKeyState(VK_INSERT))
		{
			MessageBoxW(NULL, L"END", L"END", MB_OK);
			FunctionImports::fnSetMouseCursorVisible(false);
		}		
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, 0, (unsigned long(__stdcall*)(void*))MainLoop, NULL, 0, NULL);
	}
	return TRUE;
}