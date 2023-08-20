#pragma once

#include <glad/glad.h>
#include "engine/core/component.h"

namespace Engine::Rendering {
    struct Mesh : Component {
        public:
            Mesh(GLuint _vaoId, int _vertexCount);
            int getVaoId();
            int getVertexCount();

        private:
            GLuint vaoId;
            int vertexCount;
    };
}