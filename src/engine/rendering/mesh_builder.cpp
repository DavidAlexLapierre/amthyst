#include "engine/rendering/mesh_builder.h"

namespace Amethyst {
    std::shared_ptr<Mesh> MeshBuilder::createSprite() {
        auto mesh = std::make_shared<Mesh>();
        mesh->geometry = Quad();

        return mesh;
    }
}