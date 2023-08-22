#pragma once

#include <glad/glad.h>
#include <iostream>
#include <vector>

namespace Amethyst {
    class Shader {
        public:
            Shader(const char* vertexCode, const char* fragmentCode);
            void start();
            void stop();
            void enableAttributes();
            void disableAttributes();
            void dispose();
        
        private:
            static GLuint loadShader(const char* code, GLenum type);
            std::vector<int> attributes;
            GLuint vertexShader;
            GLuint fragmentShader;
            GLuint program;

        protected:
            void bindAttribute(int attribute, const char *string);
            GLint getUniformLocation(const char* name);
            virtual void bindAttributes() {}
    };
}