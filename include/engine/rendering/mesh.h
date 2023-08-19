#pragma once

namespace Engine::Rendering {
    class Mesh {
        public:
            Mesh();
            int getVaoId();
            int getVertexCount();

        private:
            int vaoId;
            int vertexCount;
    };
}