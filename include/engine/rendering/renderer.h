#pragma once

#include "engine/rendering/mesh.h"
#include "engine/rendering/mesh_loader.h"
#include "engine/utils/event_handler.h"
#include "engine/core/entity.h"
#include <string>
#include <memory>
#include <unordered_map>

namespace Engine::Rendering {
    class Mesh;

    class Renderer {
        public:
            Renderer();
            void update(double deltaT);
            void draw();

        private:
            void render(std::shared_ptr<Mesh> mesh, std::string id);
            void registerEntity(const void* data);
            MeshLoader loader;
            std::unordered_map<std::string, std::shared_ptr<Entity>> entities;
    };
}