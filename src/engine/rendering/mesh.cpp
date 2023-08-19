#include "engine/rendering/mesh.h"

namespace Engine::Rendering {
    Mesh::Mesh() {

    }

    int Mesh::getVaoId() { return vaoId; }
    int Mesh::getVertexCount() { return vertexCount; }
}