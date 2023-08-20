#pragma once

#include <glad/glad.h>
#include "engine/rendering/geometry.h"
#include "engine/core/component.h"

namespace Engine::Rendering {
    struct Mesh : public Component {
        public:
            int getVaoId() const { return vaoId; }
            Geometry geometry;

        private:
            GLuint vaoId;
    };
}