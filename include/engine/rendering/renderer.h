#pragma once

#include "engine/rendering/mesh.h"
#include "engine/core/system.h"

namespace Engine::Rendering {
    class Renderer : public System {
        public:
            Renderer(std::vector<std::type_index> components) : System(components) {}
            void init() override;

        private:
            void render(std::shared_ptr<Mesh> mesh);

        protected:
            void dispose() override;
            void update(int deltaT) override;
    };
}