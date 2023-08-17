#include "engine/ECS/system_manager.h"

namespace Engine::ECS {

    void SystemManager::registerSystem(std::shared_ptr<System> system) {
        systems.push_back(system);
    }

    void SystemManager::update(int deltaT) {
        for (auto system : systems) {
            system->updateEntities(deltaT);
        }
    }

    bool SystemManager::entityMatchesSystem(std::shared_ptr<Entity> entity, std::shared_ptr<System> system) {
        for (const std::type_index systemType : system->getComponents()) {
            auto components = entity->getComponents();
            if (components.find(systemType) == components.end()) {
                return false;
            }
        }

        return true;
    }
}