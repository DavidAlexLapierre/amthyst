#pragma once

#include <vector>
#include <memory>

namespace Amethyst {
    struct Geometry {
        public:
            std::vector<float> vertices;
            std::vector<int> indices;
            int vertexCount() { return indices.size(); }
    };
}