#include "engine/utils/event_handler.h"

namespace Engine::Utils {

    EventHandler& EventHandler::instance() {
        static EventHandler _instance;
        return _instance;
    }

    void EventHandler::listen(const Events event, std::function<void()> callback) {
                eventCallbacks[event].push_back(callback);
    }

    void EventHandler::emit(const Events event) {
        if (eventCallbacks.find(event) != eventCallbacks.end()) {
            for (const auto& callback : eventCallbacks[event]) {
                callback();
            }
        }
    }
}