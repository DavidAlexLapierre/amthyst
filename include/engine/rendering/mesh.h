#pragma once

#include <glad/glad.h>
#include <glm/vec3.hpp>
#include "engine/rendering/geometry.h"
#include "engine/rendering/material.h"
#include "engine/core/component.h"

namespace Amethyst {
    struct Mesh : public Component {
        public:
            Geometry geometry;
            Material material;
            glm::vec3 pos;
    };
}