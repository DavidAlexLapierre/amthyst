#include "engine/rendering/renderer.h"

namespace Engine::Rendering {

    Renderer::Renderer() {
        loader = MeshLoader();
    }

    void Renderer::registerEntity(std::shared_ptr<Entity> entity) {
        if (entity) {
            auto mesh = entity->getComponent<Mesh>();
            if (mesh) {
                entities[entity->id().toString()] = entity;
                auto id = entity->id().toString();
                loader.loadToVao(entity->id(), mesh);
            }
        }
    }

    void Renderer::cleanEntityRegistry() {
        loader.dispose();
        entities.clear();
    }

    void Renderer::update(double deltaT) {
        // ADD SPECIFIC SYSTEM UPDATE LOGIC LIKE ANIMATION/SPRITE/ETC
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