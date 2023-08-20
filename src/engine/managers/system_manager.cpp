#include "engine/managers/system_manager.h"

namespace Engine::Managers {

    SystemManager::SystemManager() {
        Utils::EventHandler::instance().listen(Utils::Events::ADD_ENTITY, [this](const void *data) { addEntity(data); });
    }

    void SystemManager::addEntity(const void *data) {
        if (data) {
            auto entity = Utils::EventHandler::instance().toSharedPtr<Entity>(data);
            for (auto system : systems) {
                if (entityMatchesSystem(entity, system)) {
                    system->registerEntity(entity);
                }
            }
        }
    }

    void SystemManager::registerSystem(std::shared_ptr<System> system) {
        systems.push_back(system);
    }

    void SystemManager::update(int deltaT) {
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
}