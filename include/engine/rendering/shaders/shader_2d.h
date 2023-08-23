#pragma once

#include "engine/rendering/shader.h"

namespace Amethyst {
    class Shader2D : public Shader {
        public:
            Shader2D() : Shader() {
                init(vertexCode, fragmentCode);
            }

        private:
            const char* vertexCode = R"(
                #version 400 core

                in vec3 position;
                out vec3 color;

                void main(void) {
                    gl_Position = vec4(position, 1.0);
                    color = vec3(position.x+0.5, 1.0, position.y+0.5);
                }
            )";

            const char* fragmentCode = R"(
                #version 400 core

                in vec3 color;
                out vec4 outColor;

                void main(void) {
                    outColor = vec4(color, 1.0);
                }
            )";

        protected:
            void bindAttributes() override {
                bindAttribute(0, "position");
            }
    };
}