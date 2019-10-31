#pragma once
#include "Actor.h"

/*
struct __cppobj __declspec(align(8)) Black::Actor::Component::PadControl::ActorPadControlComponent : Black::Actor::Component::PadControl::IActorPadControl
{
  Black::Actor::Actor *pOwnerActor_;
  bool isEnableControllerButton_;
  bool buttonPush[18];
  bool buttonTrigger[18];
  bool buttonRelease[18];
  float buttonRepeat[18];
  float buttonPushedTime[18];
  float buttonReleasedTime[18];
  bool buttonReserve[18];
  bool buttonReset[18];
  bool buttonRePush[18];
  bool buttonResetPush[18];
  float stickInputTimeL;
  float stickInputTimeR;
  bool commandPush[174];
  bool commandTrigger[174];
  bool commandRelease[174];
  float commandRepeat[174];
  float commandPushedTime[174];
  float commandReleasedTime[174];
  bool commandReserve[174];
  bool commandReset[174];
  bool commandRePush[174];
  bool commandResetPush[174];
  bool isEnableControllerLStick_;
  bool isEnableControllerRStick_;
  int padNo;
  bool lstickChangeCheck_;
  float lstickChangeDir_;
};
*/

struct ActorPadControlComponent
{
	Actor* pOwnerActor_;
	bool isEnableControllerButton_;
	bool buttonPush[18];
	bool buttonTrigger[18];
	bool buttonRelease[18];
	float buttonRepeat[18];
	float buttonPushedTime[18];
	float buttonReleasedTime[18];
	bool buttonReserve[18];
	bool buttonReset[18];
	bool buttonRePush[18];
	bool buttonResetPush[18];
	float stickInputTimeL;
	float stickInputTimeR;
	bool commandPush[174];
	bool commandTrigger[174];
	bool commandRelease[174];
	float commandRepeat[174];
	float commandPushedTime[174];
	float commandReleasedTime[174];
	bool commandReserve[174];
	bool commandReset[174];
	bool commandRePush[174];
	bool commandResetPush[174];
	bool isEnableControllerLStick_;
	bool isEnableControllerRStick_;
	int padNo;
	bool lstickChangeCheck_;
	float lstickChangeDir_;
};