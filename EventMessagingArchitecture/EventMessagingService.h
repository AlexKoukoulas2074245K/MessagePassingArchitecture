#pragma once

#include <unordered_map>
#include <functional>

#include "EventTypes.h"

class EventListener;
class Event;
class EventMessagingService final
{
public:    
    using EventCallback = std::function<void(const Event&)>;

public:
    EventMessagingService(); 

    void RegisterListener(const EventType eventType, const EventListener& eventListener, EventCallback eventCallback);
    void UnregisterListener(const EventType eventType, const EventListener& eventListener);
    void UnregisterListenerFromAllEvents(const EventListener& eventListener);
    void DispatchEvent(const Event& event);

private:
    using EventListenerMap = std::unordered_map<const EventListener*, EventCallback>;

    std::unordered_map<EventType, EventListenerMap> _listeners;
};