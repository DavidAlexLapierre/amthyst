#include "engine/rendering/renderer.h"

namespace Engine::Rendering {

    Renderer::Renderer() {
        Utils::EventHandler::instance().listen(Utils::Events::ADD_ENTITY, [this](const void *data) { registerEntity(data); });
    }

    void Renderer::registerEntity(const void* data) {
        if (data) {
            auto entity = Utils::EventHandler::instance().toSharedPtr<Entity>(data);
            entities[entity->id().toString()] = entity;
        }
    }

    void Renderer::update(double deltaT) {

    }

    void Renderer::draw() {
        for (auto entity : entities) {
            auto mesh = entity.second.get()->getComponent<Mesh>();
            render(mesh);
        }
    }

    void Renderer::render(std::shared_ptr<Mesh> mesh) {
        glBindVertexArray(mesh->getVaoId());
        glEnableVertexAttribArray(0);
        glDrawArrays(GL_TRIANGLES, 0, mesh->geometry.vertexCount());
        glDisableVertexAttribArray(0);
        glBindVertexArray(0);
    }
}