#include "EventListener.h"
#include "EventMessagingService.h"
#include "Event.h"

#include <iostream>

class GameObjectListensToOne: public EventListener
{
public:
    GameObjectListensToOne(EventMessagingService& eventMessagingService)
        : EventListener(eventMessagingService)
    {
        eventMessagingService.RegisterListener(EventType::GAME_OBJECT_COLLISION, *this, [this](const Event& event){ HandleEvent(event.GetEventType()); });
    }

    void HandleEvent(const EventType& eventType)
    {
        std::cout << "GameObjectListensToOne handles event: " << eventType << std::endl; 
    }
};

class GameObjectListensToBoth: public EventListener
{
public:
    GameObjectListensToBoth(EventMessagingService& eventMessagingService)
        : EventListener(eventMessagingService)
    {
        eventMessagingService.RegisterListener(EventType::GAME_OBJECT_COLLISION, *this, [this](const Event& event) { HandleEvent(event.GetEventType()); });
        eventMessagingService.RegisterListener(EventType::GAME_OBJECT_DESTRUCTION, *this, [this](const Event& event) { HandleEvent(event.GetEventType()); });
    }

    void HandleEvent(const EventType& eventType)
    {
        std::cout << "GameObjectListensToBoth handles event: " << eventType << std::endl;
    }
};

int main(int argc, char* argv[])
{
    EventMessagingService ems;
    GameObjectListensToOne gameObjectA(ems);
    GameObjectListensToBoth gameObjectB(ems);

    Event collision(EventType::GAME_OBJECT_COLLISION, nullptr);
    Event destruction(EventType::GAME_OBJECT_DESTRUCTION, nullptr);

    ems.DispatchEvent(collision);
    ems.DispatchEvent(destruction);

    return 0;
}