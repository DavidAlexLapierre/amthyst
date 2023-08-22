#include "engine/rendering/mesh_loader.h"

namespace Amethyst {
    void MeshLoader::loadToVao(std::string id, std::shared_ptr<Mesh> mesh) {
        createVao(id);
        bindIndices(mesh->geometry.indices);
        storeDataInAttributeList(0, 3, mesh->geometry.vertices);
        glBindVertexArray(0);
    }

    void MeshLoader::createVao(std::string id) {
        GLuint vao;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        vaos[id] = vao;
    }

    void MeshLoader::bindIndices(std::vector<int> data) {
        GLuint vbo;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * data.size(), data.data(), GL_STATIC_DRAW);
        vbos.push_back(vbo);
    }

    void MeshLoader::storeDataInAttributeList(int attributeNumber, int size, std::vector<float> data) {
        GLuint vbo;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(attributeNumber, size, GL_FLOAT, false, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        vbos.push_back(vbo);
    }

    void MeshLoader::storeDataInAttributeList(int attributeNumber, int size, std::vector<int> data) {
        GLuint vbo;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(int) * data.size(), data.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(attributeNumber, size, GL_INT, false, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        vbos.push_back(vbo);
    }

    void MeshLoader::dispose() {
        for (auto pair : vaos) {
            GLuint vao = pair.second;
            glDeleteVertexArrays(1, &vao);
        }

        for (auto vbo : vbos) {
            glDeleteBuffers(1, &vbo);
        }

        vaos.clear();
        vbos.clear();
    }

    GLuint MeshLoader::getVao(std::string id) {
        auto iter = vaos.find(id);
        if (iter != vaos.end()) {
            return iter->second;
        }
        return -1;
    }
}