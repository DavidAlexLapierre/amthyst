#pragma once

#include "engine/managers/system_manager.h"
#include "engine/data/color.h"
#include "engine/core/entity.h"
#include <string>
#include <vector>
#include <memory>

class Scene : public std::enable_shared_from_this<Scene> {
    public:
        Scene(const std::string name);
        virtual void init() = 0;
        virtual void dispose() = 0;
        const std::string getName();
        Data::Color getBackgroundColor();
        void update(double deltaT);
        void createEntity(std::shared_ptr<Entity> entity);

    private:
        std::unique_ptr<Engine::Managers::SystemManager> systemManager;
        Data::Color backgroundColor;
        std::string name;

    protected:
        void setColor(Data::Color c);
};