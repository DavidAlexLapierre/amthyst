#include "engine/rendering/renderer.h"

namespace Engine::Rendering {

    void Renderer::update(int deltaT) {
        //auto mesh = entity->getComponent<Mesh>();
        //render(mesh);
    }

    void Renderer::render(std::shared_ptr<Mesh> mesh) {
        glBindVertexArray(mesh->getVaoId());
        glEnableVertexAttribArray(0);
        glDrawArrays(GL_TRIANGLES, 0, mesh->getVertexCount());
        glDisableVertexAttribArray(0);
        glBindVertexArray(0);
    }

    void Renderer::init() {

    }

    void Renderer::dispose() {

    }
}