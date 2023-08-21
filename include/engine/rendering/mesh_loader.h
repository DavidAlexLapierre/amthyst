#pragma once

#include <glad/glad.h>
#include "engine/rendering/mesh.h"
#include "engine/rendering/geometry.h"
#include "engine/data/uuid.h"
#include <vector>
#include <memory>
#include <unordered_map>

namespace Engine::Rendering {
    class MeshLoader {
        public:
            void loadToVao(Data::UUID entityId, std::shared_ptr<Mesh> mesh);
            void createVao(std::string id);
            GLuint getVao(std::string id);
            GLuint getVbo(std::string id);
            void dispose();

        private:
            std::unordered_map<std::string, GLuint> vaos;
            std::unordered_map<std::string, GLuint> vbos;
            void storeDataInAttributeList(std::string id, int attributeNumber, std::vector<float> data);
            void unbindVao();
    };
}