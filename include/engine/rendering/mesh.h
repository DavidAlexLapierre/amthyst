#pragma once

#include <glad/glad.h>
#include <glm/vec3.hpp>
#include "engine/rendering/geometry.h"
#include "engine/core/component.h"

namespace Engine::Rendering {
    struct Mesh : public Component {
        public:
            Geometry geometry;
            glm::vec3 pos;
    };
}