#include "engine/rendering/renderer.h"

namespace Engine::Rendering {

    Renderer::Renderer() {
        loader = MeshLoader();
        Utils::EventHandler::instance().listen(Utils::Events::ADD_ENTITY, [this](const void *data) { registerEntity(data); });
    }

    void Renderer::registerEntity(const void* data) {
        if (data) {
            auto entity = Utils::EventHandler::instance().toSharedPtr<Entity>(data);
            entities[entity->id().toString()] = entity;
            auto mesh = entity->getComponent<Mesh>();
            auto id = entity->id().toString();
            loader.loadToVao(entity->id(), mesh);
        }
    }

    void Renderer::update(double deltaT) {

    }

    void Renderer::draw() {
        for (auto entity : entities) {
            auto mesh = entity.second.get()->getComponent<Mesh>();
            auto id = entity.second->id().toString();
            render(mesh, id);
        }
    }

    void Renderer::render(std::shared_ptr<Mesh> mesh, std::string id) {
        glBindVertexArray(loader.getVao(id));
        glEnableVertexAttribArray(0);
        glDrawArrays(GL_TRIANGLES, 0, mesh->geometry.vertexCount());
        glDisableVertexAttribArray(0);
        glBindVertexArray(0);
    }
}