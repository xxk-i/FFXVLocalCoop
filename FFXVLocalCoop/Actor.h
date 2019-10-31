#pragma once

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
};

struct ActorControl
{

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