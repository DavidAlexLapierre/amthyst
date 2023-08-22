#pragma once

#include <vector>

namespace Amethyst {
    struct Geometry {
        public:
            std::vector<float> vertices;
            std::vector<int> indices;
            int vertexCount() { return vertices.size() / 3; }
    };
}