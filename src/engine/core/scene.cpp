#include "engine/core/scene.h"

Scene::Scene(const std::string& _name) {
    name = _name;
}

std::string Scene::getName() { return name; }