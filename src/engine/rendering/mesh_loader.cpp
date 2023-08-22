#include "engine/rendering/mesh_loader.h"

namespace Amethyst {
    void MeshLoader::loadToVao(Amethyst::UUID entityId, std::shared_ptr<Mesh> mesh) {
        createVao(entityId.toString());
        storeDataInAttributeList(entityId.toString(), 0, mesh->geometry.vertices);
        glBindVertexArray(0);
    }

    void MeshLoader::createVao(std::string id) {
        GLuint vao;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        vaos[id] = vao;
    }

    void MeshLoader::storeDataInAttributeList(std::string id, int attributeNumber, std::vector<float> data) {
        GLuint vbo;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, false, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        vbos[id] = vbo;
    }

    void MeshLoader::dispose() {
        for (auto pair : vaos) {
            GLuint vao = pair.second;
            glDeleteVertexArrays(1, &vao);
        }

        for (auto pair : vbos) {
            GLuint vbo = pair.second;
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

    GLuint MeshLoader::getVbo(std::string id) {
        auto iter = vbos.find(id);
        if (iter != vbos.end()) {
            return iter->second;
        }
        return -1;
    }
}