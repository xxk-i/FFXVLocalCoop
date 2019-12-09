#pragma once
#include "ActorReference.h"
#include "Actor.h"
#include "Math.h"
#include <atomic>


struct Individuality
{
	INDIVIDUALITY_TYPE individualityType_;
	char registerWeaponActorArray_[0x10];
	unsigned int lastWeaponEntryId_;
	unsigned int lastLeftWeaponEntryId_;
	float gunShotDelayTime_;
	float targetChangedMaskElapsedTime_;
	float interpolationTime_;
	float startYaw_;
	float endYaw_;
	float startTilt_;
	float endTilt_;
	float inputPrevYaw_;
	float inputPrevTilt_;
	float gunAimAtPrevYaw_;
	float gunAimAtPrevTilt_;
	ActorReference gazeEnemyActor_;
	int moveType_;
	int attackType_;
	unsigned int reserveItem_;
	ActorReference reserveItemTargetActor_;
	ActorReference notAnimItemTargetActor_;
	bool bConsumeItem_;
	bool limitlessJump_;
	unsigned int priorityLockLockTarget_;
	bool bWarpAttach_;
	bool bTargetLock_;
	ActorReference lockEnemyTarget_;
	bool bCameraChanged_;
	bool bDisableMapMenu_;
	int reload_counter_;
	int playingPriority_;
	bool noParryClear_;
	bool justGuard_;
	bool nowParry_;
	bool justChase_;
	bool parallelHit_;
	bool isChaseChanceExecuting_;
	bool isShiftBreaking_;
	char weaponData_[0x10];
	int useWeaponNo_;
	int setWeaponNo_;
	int setWeaponNoLeft_;
	int attachWeaponNo_;
	int attachWeaponNoLeft_;
	bool attachWeaponWeapon3_;
	bool attachWeaponWeapon3Left_;
	int weaponParamStatus_;
	char bbWeapon_[0x10];
	char mutex_[0x30];
	int comboCount_;
	float resetComboTimer_;
	char gambit_[0x100];
	void* ownerActor;
	float moveSpeed_;
	bool isEnableTargetSearch_;
	ActorReference tpCamera_;
	bool isUsingArmedformCamera_;
	bool isUsingViewTargetCamera_;
	bool isUsingCoverCamera_;
	bool isUsingMapWarpCamera_;
	bool isUsingShortWarpCamera_;
	bool isUsingFocusCamera_;
	char lineOfFireInCoverCacheArray_[0x17];
	bool isUpdatePaused_;
	ActorControllerComponent *pIController_;
	void *pIPadControl_;
	void *pIAction_;
	void *pActorStatus_;
	int areaMode_;
	int checkAreaModeCounter_;
	float shiftBreakDistance_;
	bool bArmedform_;
	bool bArmedformEos_;
	bool bArmedformAwakening_;
	bool bEventArmedorm_;
	bool bHideArmedform_;
	unsigned __int64 eosEffect_;
	int armedformCount_;
	char armedformWeaponData_[0x10];
	char warp_sword_[0x60];
	bool forceMoveAttackFlag_;
	int forceMoveMode_;
	float forceMoveDir_;
	float forceMovePow_;
	VectorA forceMoveTargetPoint_;
	float forceMoveAttackDir_;
	float forceMoveAttackInterval_;
	char discardWeaponTriggerObserver_[0x30];
	char postAnimMessageToWeaponObserver_[0x30];
	char postAnimMessageToArmedformWeaponObserver_[0x30];
	char armedformWeaponSetPositionObserver_[0x30];
	char armedformWeaponSetVisibleObserver_[0x30];
	bool isDisableAttack_;
	char disableAttackOnTriggerObserve_[0x30];
	char disableAttackOffTriggerObserve_[0x30];
	int useMagicBottleBankNumber_;
	unsigned int useMagicId_;
	VectorA magicBottleExplosionCalculatePosition_;
	float magicBottleThrowRadian_;
	unsigned __int64 magicBottleVfxHandle_;
	char ringMagicMatrix_[0x40];
	float ringMagicChargeTime_;
	unsigned __int64 ringMagicVfxHandle_;
	ActorReference elementMagicActorAttack_;
	VectorA throwMagicBottlePosOffset;
	unsigned __int64 useItemModelVfxHandle_;
	float useItemModelVfxDispTimer_;
	bool useMyPhantomSword;
	int phantomSwordSourceType_;
	bool forcePreventEndWeapon_;
	bool isRideOnTurret_;
	bool canLeaveTurret_;
};

enum MouseCursorVisibleState
{
	MOUSECURSOR_VISIBLE = 0,
	MOUSECURSOR_INVISIBLE_TRIGGERED = 1,
	MOUSECURSOR_INVISIBLE = 2
};


struct BlackMain
{
	//Probably would be nice to have but I don't feel like implementing this right now
	char other[0xD08B];
	MouseCursorVisibleState mouseCursorVisibleState_;
	char rest[0x26];
};