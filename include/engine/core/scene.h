#pragma once

// #include "engine/rendering/renderer.h"
#include "engine/data/color.h"
#include <engine/managers/system_manager.h>
#include <string>
#include <vector>

class Scene {
    public:
        Scene(const std::string name);
        virtual void init() = 0;
        virtual void dispose() = 0;
        const std::string getName();
        Data::Color getBackgroundColor();
        void update(int deltaT);

    private:
        Data::Color backgroundColor;
        std::string name;

    protected:
        Engine::Managers::SystemManager systemManager;
        void setColor(Data::Color c);
};