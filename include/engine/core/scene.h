#pragma once

#include "engine/data/color.h"
#include <string>

class Scene {
    public:
        Scene(const std::string& name);
        virtual void init() = 0;
        virtual void dispose() = 0;
        const std::string getName();
        Data::Color getBackgroundColor();

    private:
        Data::Color backgroundColor;
        std::string name;

    protected:
        void setColor(Data::Color c);
};