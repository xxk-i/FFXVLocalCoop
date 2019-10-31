#pragma once

#include "FunctionOffsets.h"

#include "ActorManager.h"
#include "ActorPadControlComponent.h"
#include "Black.h"

#include <d3d11.h>
#include "D3D11Display.h"

typedef void(__fastcall * _SetUserControlActor)(ActorManager* ActorManager, void* actor, bool bChangePadType, bool bDebugPad, bool bSave);
typedef void(__fastcall * _ChangePlayerTemporary)(uintptr_t classPointer, uintptr_t pNextPlayerActor);
typedef void(__fastcall * _PlayerChangeIndividualityIgnis)(uintptr_t classPointer, uintptr_t pOwner, bool isPlayer);
typedef void(__fastcall * _changeIndividuality)(uintptr_t classPointer, uintptr_t actor, bool initialize);
typedef void(__fastcall * _OnSelectPlayerChangeMenu)(uintptr_t PlayerChangeManager, int playerNo);
typedef void*(__fastcall * _GetActorFromIndex)(uintptr_t ActorTypeManager, int index);
typedef void(__fastcall * _StartArmedForm)(uintptr_t Individuality, bool iEnableEffect, bool eventMode);
typedef void(__fastcall * _UpdateHolyState)(uintptr_t IndividualityNoctis, bool bForceEnd);
typedef void(__fastcall * _ActorPadControlComponent)(ActorPadControlComponent* ActorPadControlComponent, Actor* pOwnerActor);
typedef ActorManager*(__fastcall * _GetActorManagerInstance)();
typedef void*(__fastcall * _GetBuddyActor)(int buddyType);
typedef void(__fastcall * _DefaultPrintFunction)(int, const char* format);
typedef void(__fastcall * _SetController)(__int64 *ActorControllerComponent, int CONTROLLERT_TYPE, __int64 *pIControllerInterface);
typedef void(__fastcall * _GetActorControllerComponent)(__int64 *ActorControl);
typedef __int64(__fastcall * _GetNowControllerType)(__int64 *ActorControllerComponent);
typedef __int64(__fastcall * _SetMouseCursorVisible)(bool visible);
typedef ID3D11Device*(__fastcall * _GetD3DDevice)();
typedef ID3D11DeviceContext*(__fastcall * _GetD3DDeviceContext)();
typedef ID3D11DeviceContext*(__fastcall * _GetD3DDeviceImmediateContext)();
typedef void(__fastcall * _onBeginFrame)(BlackMain BlackMain);
typedef void(__fastcall * _onEndFrame)(D3D11Display* display, ID3D11DeviceContext* context);
typedef __int64(__fastcall * _WindowProcedure)(HWND__ *hWnd, unsigned int msg, unsigned __int64 wParam, __int64 lParam);
typedef void(__fastcall * _SetMouseCursorState)(HWND__ *hWnd, bool state);
typedef HWND(__fastcall * _GetWindowHandle)();

//Unused test functions I used to find the SwapChain::Present() method implementation
typedef void(__fastcall * _OnSwap)();
typedef void(__fastcall * _Release)(D3D11Display* display);

namespace FunctionImports
{
	uintptr_t modBase = (uintptr_t)GetModuleHandle(NULL);

	_PlayerChangeIndividualityIgnis fnPlayerChangeIndividualityIgnis = (_PlayerChangeIndividualityIgnis)(modBase + offPlayerChangeIndividualityIgnis);
	_ChangePlayerTemporary fnChangePlayerTemporary = (_ChangePlayerTemporary)(modBase + offChangePlayerTemporary);
	_SetUserControlActor fnSetUserControlActor = (_SetUserControlActor)(modBase + offSetUserControlActor);
	_changeIndividuality fnchangeIndividuality = (_changeIndividuality)(modBase + offChangeIndividuality);
	_OnSelectPlayerChangeMenu fnOnSelectPlayerChangeMenu = (_OnSelectPlayerChangeMenu)(modBase + offOnSelectPlayerChangeMenu);
	_GetActorFromIndex fnGetActorFromIndex = (_GetActorFromIndex)(modBase + offGetActorFromIndex);
	_StartArmedForm fnStartArmedForm = (_StartArmedForm)(modBase + offStartArmedForm);
	_UpdateHolyState fnUpdateHolyState = (_UpdateHolyState)(modBase + 323850);
	_GetActorManagerInstance fnGetActorManagerInstance = (_GetActorManagerInstance)(modBase + offGetActorManagerInstance);
	_ActorPadControlComponent fnActorPadControlComponent = (_ActorPadControlComponent)(modBase + offActorPadControlComponent);
	_GetBuddyActor fnGetBuddyActor = (_GetBuddyActor)(modBase + offGetBuddyActor);
	_DefaultPrintFunction fnDefaultPrintFunction = (_DefaultPrintFunction)(modBase + offDefaultPrintFunction);
	_GetNowControllerType fnGetNowControllerType = (_GetNowControllerType)(modBase + offGetNowControllerType);
	_SetController fnSetController = (_SetController)(modBase + offSetController);
	_GetActorControllerComponent fnGetActorControllerComponent = (_GetActorControllerComponent)(modBase + offGetActorControllerComponent);
	_GetD3DDevice fnGetD3DDevice = (_GetD3DDevice)(modBase + offGetD3DDevice);
	_GetD3DDeviceContext fnGetD3DDeviceContext = (_GetD3DDeviceContext)(modBase + offGetD3DDeviceContext);
	_GetD3DDeviceImmediateContext fnGetD3DDeviceImmediateContext = (_GetD3DDeviceImmediateContext)(modBase + offGetD3DDeviceImmediateContext);
	_OnSwap fnOnSwap = (_OnSwap)(modBase + offOnSwap);
	_Release fnRelease = (_Release)(modBase + offRelease);
	_onBeginFrame fnonBeginFrame = (_onBeginFrame)(modBase + offonBeginFrame);
	_onEndFrame	fnonEndFrame = (_onEndFrame)(modBase + offonEndFrame);
	_SetMouseCursorVisible fnSetMouseCursorVisible = (_SetMouseCursorVisible)(modBase + offSetMouseCursorVisible);
	_WindowProcedure fnWindowProcedure = (_WindowProcedure)(modBase + offWindowProcedure);
	_SetMouseCursorState fnSetMouseCursorState = (_SetMouseCursorState)(modBase + offSetMouseCursorState);
	_GetWindowHandle fnGetWindowHandle = (_GetWindowHandle)(modBase + offGetWindowHandle);
}