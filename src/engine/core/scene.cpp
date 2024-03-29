#include "engine/core/scene.h"
Scene::Scene(const std::string _name) {
    name = _name;
    backgroundColor = Amethyst::Color(20, 20, 20);
    systemManager = std::make_shared<Amethyst::SystemManager>();
}

void Scene::setColor(Amethyst::Color c) {
    backgroundColor = Amethyst::Color(c);
}

void Scene::dispose() {
    systemManager->dispose();
}

void Scene::update(double deltaT) { systemManager->update(deltaT); }

void Scene::draw() { systemManager->draw(); }

void Scene::createEntity(std::shared_ptr<Entity> entity) {
    systemManager->createEntity(entity);
}

Amethyst::Color Scene::getBackgroundColor() { return backgroundColor; }
const std::string Scene::getName() { return name; }