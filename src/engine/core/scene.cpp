#include "engine/core/scene.h"

Scene::Scene(const std::string _name) {
    name = _name;
    systemManager = Engine::Managers::SystemManager();
    backgroundColor = Data::Color(20, 20, 20);
}

void Scene::setColor(Data::Color c) {
    backgroundColor = Data::Color(c);
}

void Scene::update(int deltaT) {
    for (auto system : systemManager.getSystems()) {
        system->update(deltaT);
    }
}

Data::Color Scene::getBackgroundColor() { return backgroundColor; }
const std::string Scene::getName() { return name; }