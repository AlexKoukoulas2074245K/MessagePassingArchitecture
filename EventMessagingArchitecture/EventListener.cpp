#include "EventListener.h"
#include "EventMessagingService.h"

EventListener::EventListener(EventMessagingService& eventMessagingService)
    : _eventMessagingService(eventMessagingService)
{
}

EventListener::~EventListener()
{
    _eventMessagingService.UnregisterListenerFromAllEvents(*this);
}