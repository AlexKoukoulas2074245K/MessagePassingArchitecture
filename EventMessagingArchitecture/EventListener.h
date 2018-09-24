#pragma once

class EventMessagingService;
class EventListener
{
public:
    EventListener(EventMessagingService& eventMessagingService);
    virtual ~EventListener();

private:
    EventMessagingService& _eventMessagingService;
};