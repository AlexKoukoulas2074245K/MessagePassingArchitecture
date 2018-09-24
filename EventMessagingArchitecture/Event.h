#pragma once

#include "EventTypes.h"

class Event
{
public:
    Event();
    Event(const EventType& eventType, const void* eventPayload);
    virtual ~Event();

    const EventType& GetEventType() const;
    const void* GetEventPayload() const;

private:
    const EventType _eventType;
    const void* _eventPayload;
};