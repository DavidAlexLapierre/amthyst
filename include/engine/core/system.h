#pragma once

#include "engine/core/component.h"
#include "engine/core/entity.h"
#include "engine/data/uuid.h"
#include <map>
#include <memory>
#include <typeindex>

class System {
    public:
        virtual void update() = 0;
        virtual void init() = 0;
        void registerEntity(std::shared_ptr<Entity> entity);

    private:
        //std::vector<std::type_index> registeredComponents;
        std::map<Data::UUID, std::shared_ptr<Entity>> entities;

    protected:
        virtual void dispose() = 0;
};