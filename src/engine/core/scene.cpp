#include "engine/core/scene.h"

Scene::Scene(const std::string& _name) {
    name = _name;
}

const std::string Scene::getName() { return name; }