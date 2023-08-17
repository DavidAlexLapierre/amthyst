#pragma once

#include "engine/core/component.h"
#include "engine/core/entity.h"
#include "engine/data/uuid.h"
#include <map>
#include <memory>
#include <typeindex>
#include <string>

class System {
    public:
        System(std::vector<std::type_index> components);
        virtual void init() = 0;
        void registerEntity(std::shared_ptr<Entity> entity);
        void unregisterEntity(std::string id);
        void updateEntities(int deltaT);

    private:
        std::vector<std::type_index> registeredComponents;

    protected:
        virtual void dispose() = 0;
        virtual void update(int deltaT, std::shared_ptr<Entity> entity) = 0;
        std::map<std::string, std::shared_ptr<Entity>> entities;
};