#include "engine/core/scene.h"
Scene::Scene(const std::string _name) {
    name = _name;
    backgroundColor = Amethyst::Color(255, 255, 255);
    systemManager = std::make_unique<Amethyst::SystemManager>();
}

void Scene::setColor(Amethyst::Color c) {
    backgroundColor = Amethyst::Color(c);
}

void Scene::update(double deltaT) { systemManager->update(deltaT); }

void Scene::draw() { systemManager->draw(); }

void Scene::createEntity(std::shared_ptr<Entity> entity) {
    systemManager->createEntity(entity);
}

Amethyst::Color Scene::getBackgroundColor() { return backgroundColor; }
const std::string Scene::getName() { return name; }