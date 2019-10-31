#pragma once
//ALL DEBUG OFFSETS

//Actor Functions
__int64 offGetActorFromIndex = 0xDF850;
__int64 offGetActorManagerInstance = 0x480080;
__int64 offGetBuddyActor = 0x1187C40;

//Player Functions
__int64 offStartArmedForm = 0x13F030;
__int64 offChangePlayerTemporary = 0x8BF440;
__int64 offPlayerChangeIndividualityIgnis = 0x8BB060;

//Set
__int64 offSetUserControlActor = 0xCCCE0;
__int64 offChangeIndividuality = 0x8C0640;

//Control
__int64 offActorPadControlComponent = 0x1F8980;
__int64 offGetNowControllerType = 0x185E80;
__int64 offSetController = 0x185C50;
__int64 offGetActorControllerComponent = 0x10DE80;


//Misc
__int64 offDefaultPrintFunction = 0xBEFE0;
__int64 offOnSelectPlayerChangeMenu = 0x8BEF10;
__int64 offSetMouseCursorVisible = 0x2F851E0;
__int64 offSetMouseCursorState = 0x5039A0;
__int64 offWindowProcedure = 0x2F853C0;
__int64 offGetWindowHandle = 0xF6FF10;
__int64 offonBeginFrame = 0x503B10;

//D3D
__int64 offGetD3DDevice = 0x2F5A530;
__int64 offGetD3DDeviceContext = 0x2F5A570;
__int64 offGetD3DDeviceImmediateContext = 0x2F5A590;
__int64 offOnSwap = 0x2F5C010;
__int64 offRelease = 0x2F807E0;
__int64 offonEndFrame = 0x2F82040;