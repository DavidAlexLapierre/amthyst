#pragma once

#include "engine/utils/events.h"
#include <functional>
#include <unordered_map>
#include <vector>

namespace Engine::Utils {
    class EventHandler {
        public:
            static EventHandler &instance();
            void listen(const Events event, std::function<void()> callback);
            void emit(const Events event);

        private:
            EventHandler() = default;
            ~EventHandler() = default;
            EventHandler(const EventHandler&) = delete;
            EventHandler& operator=(const EventHandler&) = delete;

            std::unordered_map<Events, std::vector<std::function<void()>>> eventCallbacks;
    };
}