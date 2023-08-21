#pragma once

#include "engine/core/entity.h"
#include "engine/rendering/mesh.h"
#include <memory>

namespace Content {
    class Player : public Entity {
        void init() override;
        void dispose() override;
    };
}