#include "engine/core/system.h"

System::System(std::shared_ptr<Amethyst::SystemManager> _systemManager, std::vector<std::type_index> components) {
    systemManager = _systemManager;
    registeredComponents = components;
}

void System::registerEntity(std::shared_ptr<Entity> entity) {
    entities[entity->id().toString()] = entity;
}

void System::unregisterEntity(std::string id) {
    auto entity = entities[id];
    entities.erase(id);
}

void System::createEntity(std::shared_ptr<Entity> entity) { systemManager->createEntity(entity); }

std::vector<std::type_index> System::getComponents() const { return registeredComponents; }

