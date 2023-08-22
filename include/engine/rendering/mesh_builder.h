#pragma once

#include "engine/rendering/mesh.h"
#include "engine/rendering/primitives/quad.h"
#include <memory>

namespace Amethyst {
    class MeshBuilder {
        public:
            static std::shared_ptr<Mesh> createSprite();
    };
}