#pragma once

#include "engine/managers/system_manager.h"
#include "engine/rendering/renderer.h"
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
        Amethyst::Color getBackgroundColor();
        void update(double deltaT);
        void draw();
        void createEntity(std::shared_ptr<Entity> entity);

    private:
        std::shared_ptr<Amethyst::Renderer> renderer;
        std::unique_ptr<Amethyst::SystemManager> systemManager;
        Amethyst::Color backgroundColor;
        std::string name;

    protected:
        void setColor(Amethyst::Color c);
};