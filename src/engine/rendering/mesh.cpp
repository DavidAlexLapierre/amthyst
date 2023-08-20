#include "engine/rendering/mesh.h"

namespace Engine::Rendering {
    Mesh::Mesh(GLuint _vaoId, int _vertexCout) {
        vaoId = _vaoId;
        vertexCount = _vertexCout;
    }

    int Mesh::getVaoId() { return vaoId; }
    int Mesh::getVertexCount() { return vertexCount; }
}