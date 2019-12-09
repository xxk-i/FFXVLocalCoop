#pragma once
#include <atomic>

struct ObjectHandle
{
	void* vfptr;
	void* pointer;
	std::atomic<int> referenceCount_;
};

struct ActorHandle
{
	ObjectHandle handle_;
};

struct IntrusiveActorHandlePtr
{
	ActorHandle* ptr_;
};


struct ActorReference
{
	unsigned int actorId;
	ObjectHandle* handle_;
};

