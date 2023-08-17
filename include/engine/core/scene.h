#pragma once

#include <string>

class Scene {
    public:
        Scene(const std::string& name);
        virtual void init() = 0;
        std::string getName();

    private:
        std::string name;
};