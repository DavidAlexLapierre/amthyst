#pragma once

#include "engine/core/entity.h"
#include "engine/rendering/mesh_builder.h"
#include "engine/rendering/mesh.h"
#include <memory>

namespace Content {
    class Player : public Entity {
        public:
            void init() override;
    };
}