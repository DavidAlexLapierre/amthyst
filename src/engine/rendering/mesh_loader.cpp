#include "engine/rendering/mesh_loader.h"

namespace Engine::Rendering {
    Mesh MeshLoader::loadToVao(std::vector<float> positions) {
        GLuint vaoId = createVao();
        storeDataInAttributeList(0, positions);
        unbindVao();
        auto geoData = Geometry();
        geoData.vertices = positions;

        auto mesh = Mesh();
        mesh.geometry = geoData;

        return mesh;
    }

    GLuint MeshLoader::createVao() {
        GLuint vao;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        vaos.push_back(vao);
        return vao;;
    }

    void MeshLoader::storeDataInAttributeList(int attributeNumber, std::vector<float> data) {
        GLuint vbo;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, false, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        vbos.push_back(vbo);
    }

    void MeshLoader::unbindVao() {
        glBindVertexArray(0);
    }

    void MeshLoader::dispose() {
        for (auto vao : vaos) {
            glDeleteVertexArrays(1, &vao);
        }

        for (auto vbo : vbos) {
            glDeleteBuffers(1, &vbo);
        }
    }
}