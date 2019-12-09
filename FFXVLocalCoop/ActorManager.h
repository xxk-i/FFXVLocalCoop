#pragma once
#pragma once
#include "PartyCreateTask.h"
#include "ActorReference.h"
#include "Math.h"
#include "Actor.h"

enum RideVehicleStatus
{
	type1,
	type2,
	type3
};

struct ActorResourceManager
{

};

enum SAVE_PLAYER
{
	SAVE_PLAYER_NONE = 0xFFFFFFFF,
	SAVE_PLAYER_NOCTIS = 0x0,
	SAVE_PLAYER_GLADIOLUS = 0x1,
	SAVE_PLAYER_IGNIS = 0x2,
	SAVE_PLAYER_PROMPTO = 0x3,
	SAVE_PLAYER_ARDYN = 0x4,
	SAVE_PLAYER_ARANEA = 0x5,
	SAVE_PLAYER_COR = 0x6,
	SAVE_PLAYER_IRIS = 0x7,
	SAVE_PLAYER_UMBRA = 0x8,
	SAVE_PLAYER_GENTIANA = 0x9,
	SAVE_PLAYER_TITAN = 0xA,
	SAVE_PLAYER_AVATAR = 0xB,
	SAVE_PLAYER_MULTIPLAYER_BUDDY1 = 0xC,
	SAVE_PLAYER_MULTIPLAYER_BUDDY2 = 0xD,
	SAVE_PLAYER_MULTIPLAYER_BUDDY3 = 0xE,
	SAVE_PLAYER_RAVUS = 0xF,
	SAVE_PLAYER_LUNA = 0x10,
	SAVE_PLAYER_RESERVE7 = 0x11,
	SAVE_PLAYER_RESERVE8 = 0x12,
	SAVE_PLAYER_AMOUNT = 0x13,
};

struct InspirationStruct
{
	unsigned int id;
	int next;
};

struct InspirationOrderWaitData
{
	unsigned int id;
	SAVE_PLAYER playerBankNumber;
	bool isUse;
	int index;
};

struct ActorInspiration
{
	InspirationStruct inspiration_[2048];
	int inspirationTop_[32];
	InspirationOrderWaitData requestList_[32];
	int requestCounter_;
};

struct Mutex
{
	BYTE gap0[1];
	_RTL_CRITICAL_SECTION criticalSection;
};

/*
struct __cppobj Black::ActorManager::ActorManager::PlayerPositionBuffer
{
bool exist;
SQEX::Luminous::Math::DoubleVector4 position;
SQEX::Luminous::Math::VectorA rotation;
};
*/

struct PlayerPositionBuffer
{
	bool exist;
	DoubleVector4 position;
	VectorA	rotation;
};

struct ActorTypeManager
{
	//fuck this struct its bigger and im done
	char temp[0x5C0]; //dec 1472
};

struct NpcStruct
{
	unsigned int object_entry_id;
	ActorReference actor_reference;
};

/*
struct std::array<ActorTypeManager, 21>
{
	ActorTypeManager _Elems[21];
}
*/
//__declspec(align(16))
struct ActorManager
{
	PartyCreateTask* partyCreateTask_;
	int currentRideVehicleStatus_;
	bool fishingPlaying_;
	bool isLmAnimationResetAllDynamicPoolsToMinSizeWaitings_;
	bool userControlStatusType_[19];
	bool userControlStatus_;
	bool userInteractionStatusType_[19];
	bool userInteractionStatus_;
	//ActorInspiration inspiration_;
	char inspiration[17031];
	char actorLodUpdater_[224];
	char deleteActorList_[16];
	char deleteActorListMutex_[48];
	///Mutex lockMutex_;
	char lockMutex_[0x30];
	Actor* userControlActor_;
	Actor* userControlPlayer_;
	Actor* userControlVehicle_;
	ActorReference partyActor_[5];
	ActorReference playerActor_[19];
	PlayerPositionBuffer playerPositionBuffer_[19];
	NpcStruct* npc_[37];
	char actorTypeManagers_[0x78C0]; //std::array<ActorTypeManager, 21>
	bool isPartyLoaded;
	char updateActorMapArray_[0x10]; //SQEX::Ebony::Std::DynamicArray<Black::Actor::ActorReference, 119, 16>
	ActorResourceManager* resourceManagerPtr_[3];
	//SQEX::Luminous::Core::Task::Task
	char actorMapUpdateTask_[0x60];
	char actorMapTransformTask_[0x60];
	char actorNodeTargetPointUpdateTask_[0x60];
	char actorEventTriggerUpdateTask_[0x60];
	char actorNodePointUpdateTask_[0x60];
	char actorWayPointUpdateTask_[0x60];
	char actorSpawnPointUpdateTask_[0x60];
	char actorInteractionPointUpdateTask_[0x60];
	//SQEX::Luminous::Core::Task::Task
	char parallel_[0x90];
	bool updating_;
	char asyncTerminateTask_[0x58]; //SQEX::Luminous::Core::Task::Parallel
	char asyncTerminateActors_[0x10]; //SQEX::Ebony::Std::DynamicArray<Black::Actor::Actor *, 2, 16>
	bool isExecutingActorUpdatePhase_;
	bool memoryEmergencyMode_;
};


/*
struct __cppobj __declspec(align(16)) Black::ActorManager::ActorManager
{
	Black::ActorManager::ActorManager::PartyCreateTask *partyCreateTask_;
	Black::Include::RideVehicleStatus currentRideVehicleStatus_;
	bool fishingPlaying_;
	bool isLmAnimationResetAllDynamicPoolsToMinSizeWaiting_;
	bool userControlStatusType_[19];
	bool userControlStatus_;
	bool userInteractionStatusType_[19];
	bool userInteractionStatus_;
	Black::ActorManager::ActorInspiration inspiration_;
	Black::Actor::Component::LOD::ActorLODUpdater actorLodUpdater_;
	SQEX::Ebony::Std::DynamicArray<Black::Actor::ActorReference,119,16> deleteActorList_;
	SQEX::Luminous::Core::Threading::Mutex deleteActorListMutex_;
	SQEX::Luminous::Core::Threading::Mutex lockMutex_;
	Black::Actor::Actor *userControlActor_;
	Black::Actor::Actor *userControlPlayer_;
	Black::Actor::Actor *userControlVehicle_;
	Black::Actor::ActorReference partyActor_[5];
	Black::Actor::ActorReference playerActor_[19];
	Black::ActorManager::ActorManager::PlayerPositionBuffer playerPositionBuffer_[19];
	Black::ActorManager::ActorManager::NpcStruct npc_[37];
	std::array<Black::ActorManager::ActorTypeManager,21> actorTypeManagers_;
	bool isPartyLoaded_;
	SQEX::Ebony::Std::DynamicArray<Black::Actor::ActorReference,119,16> updateActorMapArray_;
	Black::ActorManager::ActorResourceManager *resourceManagerPtr_[3];
	SQEX::Luminous::Core::Task::Task actorMapUpdateTask_;
	SQEX::Luminous::Core::Task::Task actorMapTransformTask_;
	SQEX::Luminous::Core::Task::Task actorNodeTargetPointUpdateTask_;
	SQEX::Luminous::Core::Task::Task actorEventTriggerUpdateTask_;
	SQEX::Luminous::Core::Task::Task actorNodePointUpdateTask_;
	SQEX::Luminous::Core::Task::Task actorWayPointUpdateTask_;
	SQEX::Luminous::Core::Task::Task actorSpawnPointUpdateTask_;
	SQEX::Luminous::Core::Task::Task actorInteractionPointUpdateTask_;
	SQEX::Luminous::Core::Task::Parallel parallel_;
	bool updating_;
	SQEX::Luminous::Core::Task::AsyncTask asyncTerminateTask_;
	SQEX::Ebony::Std::DynamicArray<Black::Actor::Actor *,2,16> asyncTerminateActors_;
	bool isExecutingActorUpdatePhase_;
	bool memoryEmergencyMode_;
};
*/