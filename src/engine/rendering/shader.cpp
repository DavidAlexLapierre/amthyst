#include "engine/rendering/shader.h"

namespace Amethyst {
    Shader::Shader(const char* vertexCode, const char* fragmentCode) {
        vertexShader = Shader::loadShader(vertexCode, GL_VERTEX_SHADER);
        fragmentShader = Shader::loadShader(fragmentCode, GL_FRAGMENT_SHADER);
        program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        bindAttributes();
        glLinkProgram(program);
        glValidateProgram(program);
    }

    void Shader::start() { glUseProgram(program); }
    void Shader::stop() { glUseProgram(0); }

    void Shader::dispose() {
        disableAttributes();
        stop();
        glDetachShader(program, vertexShader);
        glDetachShader(program, fragmentShader);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        glDeleteProgram(program);
        attributes.clear();
    }

    void Shader::enableAttributes() {
        for (auto attribute : attributes) {
            glEnableVertexAttribArray(attribute);
        }
    }

    void Shader::disableAttributes() {
        for (auto attribute : attributes) {
            glDisableVertexAttribArray(attribute);
        }
    }

    void Shader::bindAttribute(int attribute, const char* name) {
        attributes.push_back(attribute);
        glBindAttribLocation(program, attribute, name);
    }

    GLint Shader::getUniformLocation(const char* name) {
        return glGetUniformLocation(program, name);
    }

    GLuint Shader::loadShader(const char* code, GLenum type) {
        auto shader = glCreateShader(type);
        glShaderSource(shader, 1, &code, nullptr);
        glCompileShader(shader);
        // Check vertex shader compilation status
        GLint success;
        GLchar infoLog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, sizeof(infoLog), nullptr, infoLog);
            std::cerr << "Vertex shader compilation failed:\n" << infoLog << std::endl;
        }
        else
        {
            std::cout << "Vertex shader compiled successfully!" << std::endl;
        }

        return shader;
    }
}