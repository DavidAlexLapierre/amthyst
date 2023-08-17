#pragma once

#include "engine/utils/events.h"
#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>

namespace Engine::Utils {
    class EventHandler {
    public:
        using EventCallback = std::function<void(const void*)>;

        static EventHandler& instance() {
            static EventHandler instance;
            return instance;
        }

        void listen(Events event, EventCallback callback) {
            eventCallbacks_[event].push_back(callback);
        }

        void emit(Events event, const void* data = nullptr) {
            for (const EventCallback& callback : eventCallbacks_[event]) {
                callback(data);
            }
        }

        template <typename T>
        std::shared_ptr<T> toSharedPtr(const void *data) {
            return std::shared_ptr<T>(reinterpret_cast<T*>(const_cast<void*>(data)));
        }

    private:
        EventHandler() = default;
        ~EventHandler() = default;

        std::unordered_map<Events, std::vector<EventCallback>> eventCallbacks_;
    };

}
