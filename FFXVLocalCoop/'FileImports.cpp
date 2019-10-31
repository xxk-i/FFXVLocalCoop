#include "FunctionImports.h"
#include "FunctionOffsets.h"

public static void FunctionImports()
{
	PlayerChangeIndividualityIgnis = (_PlayerChangeIndividualityIgnis)(modBase + 0x8BB060);
	ChangePlayerTemporary = (_ChangePlayerTemporary)(modBase + 0x8BF440);
	SetUserControlActor = (_SetUserControlActor)(modBase + 0xCCCE0);
	changeIndividuality = (_changeIndividuality)(modBase + 0x8C0640);
	OnSelectPlayerChangeMenu = (_OnSelectPlayerChangeMenu)(modBase + 0x8BEF10);
	GetActorFromIndex = (_GetActorFromIndex)(modBase + 0xDF850);
	StartArmedForm = (_StartArmedForm)(modBase + 0x13F030);
	UpdateHolyState = (_UpdateHolyState)(modBase + 323850);
	GetActorManagerInstance = (_GetActorManagerInstance)(modBase + 0x480080);
	fnActorPadControlComponent = (_ActorPadControlComponent)(modBase + 0x1F8980);
	fnGetBuddyActor = (_GetBuddyActor)(modBase + 0x1187C40);
	fnDefaultPrintFunction = (_DefaultPrintFunction)(modBase + 0xBEFE0);
}