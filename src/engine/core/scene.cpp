#include "engine/core/scene.h"
Scene::Scene(const std::string _name) {
    name = _name;
    backgroundColor = Data::Color(20, 20, 20);
    systemManager = std::make_unique<Engine::Managers::SystemManager>();
}

void Scene::setColor(Data::Color c) {
    backgroundColor = Data::Color(c);
}

void Scene::update(double deltaT) {
    for (auto system : systemManager->getSystems()) {
        system->update(deltaT);
    }
}

void Scene::createEntity(std::shared_ptr<Entity> entity) { systemManager->createEntity(entity); }

Data::Color Scene::getBackgroundColor() { return backgroundColor; }
const std::string Scene::getName() { return name; }