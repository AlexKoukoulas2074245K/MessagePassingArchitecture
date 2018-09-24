#include "Event.h"

Event::Event()
    : _eventType(EventType::EMPTY_EVENT)
    , _eventPayload(nullptr)
{
}

Event::Event(const EventType& eventType, const void* eventPayload)
    : _eventType(eventType)
    , _eventPayload(eventPayload)
{
}

Event::~Event()
{
}

const EventType& Event::GetEventType() const
{
    return _eventType;
}

const void* Event::GetEventPayload() const
{
    return _eventPayload;
}