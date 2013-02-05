#include "BlocoUtility.h"


IEventManager BLOCO_UTILITY_API* g_pEventMgr = NULL;
IEventManager BLOCO_UTILITY_API * IEventManager::Get()
{
	return g_pEventMgr;
}

 BLOCO_UTILITY_API IEventManager::IEventManager(
	char const * const pName,
	bool setAsGlobal )
{
	if ( setAsGlobal )
		g_pEventMgr = this;
}

 BLOCO_UTILITY_API IEventManager::~IEventManager()
{
	if ( g_pEventMgr == this )
		g_pEventMgr = NULL;
}


// lastly, some macros that make it less difficult to safely use
// a possibly not-ready system ...

bool BLOCO_UTILITY_API  safeAddListener( EventListenerPtr const & inHandler, EventType const & inType )
{
	assert(IEventManager::Get() && _T("No event manager!"));
	return IEventManager::Get()->VAddListener( inHandler, inType );
}
bool BLOCO_UTILITY_API  safeDelListener( EventListenerPtr const & inHandler, EventType const & inType )
{
	assert(IEventManager::Get() && _T("No event manager!"));
	return IEventManager::Get()->VDelListener( inHandler, inType );
}
bool BLOCO_UTILITY_API  safeTriggerEvent( IEventData const & inEvent )
{
	assert(IEventManager::Get() && _T("No event manager!"));
	return IEventManager::Get()->VTrigger( inEvent );
}
bool BLOCO_UTILITY_API  safeQueEvent( IEventDataPtr const & inEvent )
{
	assert(IEventManager::Get() && _T("No event manager!"));
	return IEventManager::Get()->VQueueEvent( inEvent );
}
bool BLOCO_UTILITY_API  safeAbortEvent( EventType const & inType, bool allOfType /*= false*/ )
{
	assert(IEventManager::Get() && _T("No event manager!"));
	return IEventManager::Get()->VAbortEvent( inType, allOfType );
}
bool BLOCO_UTILITY_API  safeTickEventManager( unsigned long maxMillis /*= kINFINITE*/ )
{
	assert(IEventManager::Get() && _T("No event manager!"));
	return IEventManager::Get()->VTick( maxMillis );
}
bool BLOCO_UTILITY_API  safeValidateEventType( EventType const & inType )
{
	assert(IEventManager::Get() && _T("No event manager!"));
	return IEventManager::Get()->VValidateType( inType );
}
void BLOCO_UTILITY_API  safeSetDebugView(DebugView* pDebugView)
{
	assert(IEventManager::Get() && _T("No event manager!"));
	return IEventManager::Get()->SetDebugView( pDebugView );
}
void BLOCO_UTILITY_API  safeRemoveDebugView()
{
	assert(IEventManager::Get() && _T("No event manager!"));
	return IEventManager::Get()->RemoveDebugView();
}






