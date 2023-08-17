#include "engine/core/system.h"

void System::registerEntity(std::shared_ptr<Entity> entity) {
    auto id = entity->id();
    //entities[id] = entity;
}

