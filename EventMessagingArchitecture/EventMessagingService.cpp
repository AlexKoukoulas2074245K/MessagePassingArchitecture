#pragma once

#include "EventMessagingService.h"
#include "Event.h"

#include <algorithm>

EventMessagingService::EventMessagingService()
    : _listeners{ {EventType::GAME_OBJECT_COLLISION,{}},
                  {EventType::GAME_OBJECT_DESTRUCTION,{}} }
{
}

void EventMessagingService::RegisterListener(const EventType eventType, const EventListener& eventListener, EventCallback eventCallback)
{
    _listeners[eventType][&eventListener] = eventCallback;
}

void EventMessagingService::UnregisterListener(const EventType eventType, const EventListener& eventListener)
{
    _listeners[eventType].erase(&eventListener);
}

void EventMessagingService::UnregisterListenerFromAllEvents(const EventListener& eventListener)
{
    for (auto pair: _listeners)
    {
        pair.second.erase(&eventListener);
    }    
}

void EventMessagingService::DispatchEvent(const Event& event)
{
    const auto& eventMap = _listeners[event.GetEventType()];
    std::for_each(eventMap.begin(), eventMap.end(), [&event](std::pair<const EventListener*, EventCallback> pair){ pair.second(event); });
}


