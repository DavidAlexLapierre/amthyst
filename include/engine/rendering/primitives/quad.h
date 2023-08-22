#pragma once 

#include "engine/rendering/geometry.h"

namespace Amethyst {
    class Quad : public Geometry {
        public:
            Quad() : Geometry() {
                vertices = {
                    -0.5f, 0.5f, 0,
                    -0.5f, -0.5f, 0,
                    0.5f, -0.5f, 0,
                    0.5f, 0.5f, 0
                };

                indices = {
                    0, 1, 3,
                    3, 1, 2
                };
            }
    };
}