#pragma once

#include <string>

class Scene {
    public:
        Scene(const std::string& name);
        virtual void init() = 0;
        virtual void dispose() = 0;
        const std::string getName();

    private:
        std::string name;
};