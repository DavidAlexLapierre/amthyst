#include "engine/managers/system_manager.h"

namespace Engine::Managers {

    SystemManager::SystemManager(std::shared_ptr<Scene> _scene) {
        scene = _scene;
    }

    void SystemManager::registerSystem(std::shared_ptr<System> system) {
        systems.push_back(system);
    }

    void SystemManager::update(double deltaT) {
        for (auto system : systems) {
            system->update(deltaT);
        }
    }

    std::vector<std::shared_ptr<System>> SystemManager::getSystems() { return systems; }

    bool SystemManager::entityMatchesSystem(std::shared_ptr<Entity> entity, std::shared_ptr<System> system) {
        for (const std::type_index systemType : system->getComponents()) {
            auto components = entity->getComponents();
            if (components.find(systemType) == components.end()) {
                return false;
            }
        }

        return true;
    }

    void SystemManager::createEntity(std::shared_ptr<Entity> entity) {
        for (auto system : systems) {
            if (entityMatchesSystem(entity, system)) {
                system->registerEntity(entity);
            }
        }
    }
}