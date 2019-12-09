#include "ActorReference.h"
#include "Math.h"
#pragma once

enum INDIVIDUALITY_TYPE
{
	IT_NONE = 0x0,
	IT_NOCTIS = 0x1,
	IT_BUDDY = 0x2,
	IT_RAVUS = 0x3,
	IT_ARDYN = 0x4,
	IT_CHOCOBO = 0x5,
	IT_VEHICLE = 0x6,
	IT_TOAD = 0x7,
	IT_NOCTISCHILD = 0x8,
	IT_PLATINUM_MONSTER = 0x9,
	IT_LAST_IFRIT = 0xA,
	IT_MOOGLE = 0xB,
	IT_PROMPTO_PLAYER_VR = 0xC,
	IT_GLADIOLUS_PLAYER_DLC = 0xD,
	IT_TITAN = 0xE,
	IT_IGNIS_PLAYER_DLC = 0xF,
	IT_PROMPTO_PLAYER_DLC = 0x10,
	IT_GILGAMESH_DLC = 0x11,
	IT_ARANEA_PLAYER_DLC = 0x12,
	IT_AVATAR = 0x13,
	IT_BARRIER = 0x14,
	IT_NOCTIS_BOSS_DLC = 0x15,
	IT_LUNA = 0x16,
	IT_UNKNOWN = 0x17,
};

enum ID
{
	ID_PLAYER = 0x0,
	ID_ENEMY = 0x1,
	ID_NPC = 0x2,
	ID_MAP = 0x3,
	ID_MAP_OBJECT = 0x4,
	ID_PREFAB = 0x5,
	ID_CAMERA = 0x6,
	ID_WEAPON = 0x7,
	ID_ENEMY_PROJECTILE = 0x8,
	ID_LIGHT = 0x9,
	ID_WIND = 0xA,
	ID_NODE_POINT = 0xB,
	ID_WAY_POINT = 0xC,
	ID_STRONGPOINT = 0xD,
	ID_TEAM = 0xE,
	ID_SPAWN_POINT = 0xF,
	ID_PACKAGELOAD_POINT = 0x10,
	ID_EVENT_TRIGGER = 0x11,
	ID_ANIMAL = 0x12,
	ID_TARGET_POINT = 0x13,
	ID_INTERACTION_POINT = 0x14,
	ID_BOTTOM = 0x15,
	ID_ACTOR_MANAGER_AMOUNT = 0x15,
	ID_SINGLE = 0x15,
	ID_FOR_AUTHORING = 0x16,
	ID_JUNK_ENTITY = 0x16,
	ID_PREVIEW_MODE = 0x17,
	ID_AMOUNT = 0x18,
	ID_ERROR = 0x19,
	ID_MAX = 0x3F,
};

enum BATTLE_STATUS
{
	BATTLE_STATUS_OFF = 0x0,
	BATTLE_STATUS_PRECAUTION = 0x1,
	BATTLE_STATUS_ON = 0x2,
	BATTLE_STATUS_ESCAPE = 0x3,
	BATTLE_STATUS_AMOUNT = 0x4,
};

enum BgCollisionType
{
	NONE = 0x0,
	PLAYER = 0x1,
	ENEMY = 0x2,
	ENEMY_L = 0x3,
	FLYENEMY = 0x4,
	FLYENEMY_L = 0x5,
	ENEMY_SP = 0x6,
	NPC = 0x7,
	VEHICLE = 0x8,
	BUDDY = 0x9,
};

struct Actor
{
	char Entity[0x40];
	void* pActorResourceComponent;
	char pActorInteraction_[0x2];
	void* pReinforceSpawnerComponent_;
	char actorType_[0x2];
	ActorReference targetActor_;
	ActorReference targetPointActor_;
	char attachedActorList_[0x10];
	char attachedLinkageActorList_[0x10];
	void* pCurrentActorScene_;
	char handle_[0x8];
	void* next_;
	void* previous_;
	void* ownerActor_;
	VectorA position_;
	ID actorTypeID_;
	unsigned int actorID_;
	unsigned int characterID_;
	bool battleFlag_;
	bool targetCategoryFlag_[19];
	bool targetFlag_;
	bool activeFlag_;
	bool activeMaskFlag_;
	bool activeMaskCategoryFlag_[19];
	bool activeCommandFlag_;
	bool activeCommandMaskFlag_;
	bool presenceCategoryFlag_[19];
	bool presenceFlag_;
	bool canUserCommandFlag_;
	bool mayaDirectionFlag_;
	bool isPositionDirty_;
	__int8 asyncInitialized_ : 1;
	__int8 initializedComplete_ : 1;
	__int8 released_ : 1;
	__int8 terminating_ : 1;
	__int8 isNeedUpdateSequence_ : 1;
	__int8 isUseCCTForTriggerNode_ : 1;
	unsigned int updateArrayIndex_;
	void* entity;
	float lifeSpan;
	BATTLE_STATUS battleStatus_;
	BgCollisionType bgCollisionType_;
	unsigned int invalidPresence_[9];
	char asyncDestroyComponents_[0x10];
	void* pWorldPackageData_;
	void* pWorldEntityData_;
	char sceneTypeInfo_[0x8];
	char componentContainter_[0x18];
	unsigned int overwriteParamID_;
	char presetParam_[0x8C];
};

enum CONTROLLER_TYPE
{
	CONTROLLER_TYPE_NONE = 0x0,
	CONTROLLER_TYPE_PAD = 0x1,
	CONTROLLER_TYPE_SEQUENCE_VS0 = 0x2,
	CONTROLLER_TYPE_SCHEDULE_VS0 = 0x3,
	CONTROLLER_TYPE_SEQUENCE_DYNAMIC_EVENT_VS1 = 0x4,
	CONTROLLER_TYPE_AIGRAPH = 0x5,
	CONTROLLER_TYPE_DEBUG_PAD = 0x6,
	CONTROLLER_TYPE_EMPTY = 0x7,
	CONTROLLER_TYPE_KEYBOARD = 0x8,
	CONTROLLER_TYPE_MAX = 0x9,
};

struct ActorControllerComponent
{
	Actor *pOwnerActor_;
	char controllerList_[0xE0];
	CONTROLLER_TYPE nowControllerType_;
	char updateState_[0x4];
	bool bPadWithAI_;
	bool isPaused_;
	bool isDebugPaused_;
	bool bStopMove_;
	char observers[0x10];
};

struct ActorCharacter
{
	char ActorControl[0x1BF0];
	char contactPlay[0x10];
};

enum BUDDY_TYPE
{
	BUDDY_TYPE_NONE = 0xFFFFFFFF,
	BUDDY_TYPE_NOCTIS = 0x0,
	BUDDY_TYPE_GLADIOLUS = 0x1,
	BUDDY_TYPE_PROMPTO = 0x2,
	BUDDY_TYPE_IGNIS = 0x3,
	BUDDY_TYPE_GUEST = 0x4,
	BUDDY_TYPE_UCPC = 0x5,
	BUDDY_TYPE_ALL = 0xA,
};

enum CATEGORY
{
	CATEGORY_BASE = 0x0,
	CATEGORY_SYSTEM = 0x1,
	CATEGORY_BLACKOUT = 0x2,
	CATEGORY_SCRIPT = 0x3,
	CATEGORY_SORTIE = 0x4,
	CATEGORY_BATTLE = 0x5,
	CATEGORY_DRIVE = 0x6,
	CATEGORY_CUTSCENE = 0x7,
	CATEGORY_CAMERA = 0x8,
	CATEGORY_MENU = 0x9,
	CATEGORY_INTERACTION = 0xA,
	CATEGORY_SUMMON = 0xB,
	CATEGORY_PRESENCE = 0xC,
	CATEGORY_BODY = 0xD,
	CATEGORY_JOB_COMMAND = 0xE,
	CATEGORY_TOAD = 0xF,
	CATEGORY_GAMEOVER = 0x10,
	CATEGORY_DEBUG = 0x11,
	CATEGORY_BIND = 0x12,
	CATEGORY_AMOUNT = 0x13
};

struct PlayerChangeManager
{
	BUDDY_TYPE originalUCPC_;
	BUDDY_TYPE switchedUCPC_;
	BUDDY_TYPE preSwitchedUCPC_;
	unsigned int disableStatus_;
	void *pCurrentPlayerChangeIndividuality_;
	void *pEachIndividuality_[5];
	bool isPlayerChangeSelecting_;
	bool isMenuOpening_;
	bool isWaitingBattleEndForResetPlayer_;
	char specialMotionInfo_[0x34];
	float ucpcHateUpRate_[5];
	DoubleVector4 preOrigUCPCWorldPos_;
	unsigned int origUCPCNaviMapID_;
	unsigned int origUCPCBackMapID_;
	char forceChangeRequestInfo_[0x10];
	bool isAllOpenModeForDebug_;
	bool isSpecialMotion100_;
	bool isNonBattlePlayerChangeModeForDebug_;
};


/*
struct __cppobj __declspec(align(16)) Black::Actor::Actor : SQEX::Ebony::Framework::Entity::Entity
{
	std::unique_ptr<Black::Actor::Component::ActorResourceComponent, std::default_delete<Black::Actor::Component::ActorResourceComponent> > pActorResourceComponent_;
	std::unique_ptr<Black::Actor::Component::Interaction::ActorInteractionComponent, std::default_delete<Black::Actor::Component::Interaction::ActorInteractionComponent> > pActorInteraction_;
	std::unique_ptr<Black::Actor::Component::Nifl::ReinforceSpawnerComponent, std::default_delete<Black::Actor::Component::Nifl::ReinforceSpawnerComponent> > pReinforceSpawnerComponent_;
	SQEX::Ebony::Std::BitFlag<unsigned __int64> actorType_;
	Black::Actor::ActorReference targetActor_;
	Black::Actor::ActorReference targetPointActor_;
	SQEX::Ebony::Std::Map<unsigned int, Black::Actor::ActorReference, 118> attachedActorList_;
	SQEX::Ebony::Std::DynamicArray<Black::Actor::ActorReference, 118, 16> attachedLinkageActorList_;
	Black::ActorManager::ActorScene *pCurrentActorScene_;
	SQEX::Ebony::Std::IntrusivePointer<Black::Actor::ActorHandle> handle_;
	Black::Actor::Actor *next_;
	Black::Actor::Actor *previous_;
	Black::Actor::Actor *ownerActor_;
	SQEX::Luminous::Math::VectorA position_;
	Black::Include::ID actorTypeID_;
	unsigned int actorID_;
	unsigned int characterID_;
	bool battleFlag_;
	bool targetCategoryFlag_[19];
	bool targetFlag_;
	bool activeFlag_;
	bool activeMaskFlag_;
	bool activeMaskCategoryFlag_[19];
	bool activeCommandFlag_;
	bool activeCommandMaskFlag_;
	bool presenceCategoryFlag_[19];
	bool presenceFlag_;
	bool canUserCommandFlag_;
	bool mayaDirectionFlag_;
	bool isPositionDirty_;
	__int8 asyncInitialized_ : 1;
	__int8 initializedComplete_ : 1;
	__int8 released_ : 1;
	__int8 terminating_ : 1;
	__int8 isNeedUpdateSequence_ : 1;
	__int8 isUseCCTForTriggerNode_ : 1;
	unsigned int updateArrayIndex_;
	SQEX::Ebony::Framework::Entity::Entity *entity_;
	float lifeSpan_;
	Black::Actor::BATTLE_STATUS battleStatus_;
	Black::Physics::BgCollision bgCollisionType_;
	unsigned int invalidPresence_[9];
	SQEX::Ebony::Std::DynamicArray<Black::Actor::Component::ActorComponentBase *, 2, 16> asyncDestroyComponents_;
	SQEX::Ebony::Framework::Entity::EntityPackage *pWorldPackageData_;
	SQEX::Ebony::Framework::Entity::Entity *pWorldEntityData_;
	std::unique_ptr<Black::Actor::Actor::SceneTypeInfo, std::default_delete<Black::Actor::Actor::SceneTypeInfo> > sceneTypeInfo_;
	SQEX::Luminous::Component::ContainerBase componentContainer_;
	unsigned int overwriteParamID_;
	Black::AI::Buddy::Status::BuddyPresetParamGenerator::PresetParam presetParam_;
};

*/