#pragma once

#include "engine/rendering/mesh.h"
#include "engine/rendering/mesh_loader.h"
#include "engine/core/entity.h"
#include <string>
#include <memory>
#include <unordered_map>

namespace Amethyst {
    class Mesh;

    class Renderer {
        public:
            void dispose();
            void update(double deltaT);
            void draw();
            void registerEntity(std::shared_ptr<Entity> entity);

        private:
            void render(std::shared_ptr<Mesh> mesh, std::string id);
            MeshLoader loader;
            std::unordered_map<std::string, std::shared_ptr<Entity>> entities;
    };
}