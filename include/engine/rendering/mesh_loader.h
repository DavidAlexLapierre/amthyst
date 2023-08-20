#pragma once

#include "engine/rendering/mesh.h"
#include <vector>

namespace Engine::Rendering {
    class MeshLoader {
        public:
            Mesh loadToVao(std::vector<float> positions);
            GLuint createVao();
            void dispose();

        private:
            std::vector<GLuint> vaos;
            std::vector<GLuint> vbos;
            void storeDataInAttributeList(int attributeNumber, std::vector<float> data);
            void unbindVao();
    };
}