#include "engine/core/system.h"

System::System(std::vector<std::type_index> components) {
    registeredComponents = components;
}

void System::registerEntity(std::shared_ptr<Entity> entity) {
    entities[entity->id().toString()] = entity;
}

void System::unregisterEntity(std::string id) {
    auto entity = entities[id];
    entities.erase(id);
}

std::vector<std::type_index> System::getComponents() const { return registeredComponents; }

