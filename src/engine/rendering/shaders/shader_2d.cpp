#include "engine/rendering/shaders/shader_2d.h"

namespace Amethyst {
    void Shader2D::bindAttributes() {
        bindAttribute(0, "position");
    }
}

/*

TODO

Add a way to load the position and then create the shader

*/