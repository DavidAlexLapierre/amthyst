#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "engine/rendering/mesh.h"
#include "engine/rendering/geometry.h"
#include "engine/data/uuid.h"
#include <vector>
#include <memory>
#include <unordered_map>

namespace Amethyst {
    class MeshLoader {
        public:
            void loadToVao(std::string id, std::shared_ptr<Mesh> mesh);
            void createVao(std::string id);
            GLuint getVao(std::string id);
            void dispose();

        private:
            std::unordered_map<std::string, GLuint> vaos;
            std::vector<GLuint> vbos;
            void bindIndices(std::vector<int> data);
            void storeDataInAttributeList(int attributeNumber, int size, std::vector<float> data);
            void storeDataInAttributeList(int attributeNumber, int size, std::vector<int> data);
    };
}