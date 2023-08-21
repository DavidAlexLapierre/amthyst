#pragma once

#include "engine/data/color.h"
#include "engine/core/entity.h"
#include "engine/managers/system_manager.h"
#include <string>
#include <vector>
#include <memory>

namespace Engine::Managers {
    class SystemManager;
}

class Scene : public std::enable_shared_from_this<Scene> {
    public:
        Scene(const std::string name);
        virtual void init();
        virtual void dispose() = 0;
        const std::string getName();
        Data::Color getBackgroundColor();
        void update(double deltaT);
        void createEntity(std::shared_ptr<Entity> entity);

    private:
        Data::Color backgroundColor;
        std::string name;

    protected:
        std::shared_ptr<Engine::Managers::SystemManager> systemManager;
        void setColor(Data::Color c);
};