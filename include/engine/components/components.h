#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Engine::Components {

/**
 * @struct Transform
 * @brief Position, rotation, and scale component
 */
struct Transform {
    glm::vec3 position = glm::vec3(0.0f);
    glm::quat rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
    glm::vec3 scale = glm::vec3(1.0f);
    
    glm::mat4 getMatrix() const {
        glm::mat4 T = glm::translate(glm::mat4(1.0f), position);
        glm::mat4 R = glm::mat4_cast(rotation);
        glm::mat4 S = glm::scale(glm::mat4(1.0f), scale);
        return T * R * S;
    }
};

/**
 * @struct Velocity
 * @brief Linear and angular velocity for physics
 */
struct Velocity {
    glm::vec3 linear = glm::vec3(0.0f);
    glm::vec3 angular = glm::vec3(0.0f);
};

/**
 * @struct RigidBody
 * @brief Physics properties
 */
struct RigidBody {
    float mass = 1.0f;
    float drag = 0.1f;
    float angularDrag = 0.05f;
    bool useGravity = true;
    bool isKinematic = false;
};

/**
 * @struct Collider
 * @brief Collision shape
 */
struct Collider {
    enum class ShapeType { BOX, SPHERE, CAPSULE, MESH };
    
    ShapeType shapeType = ShapeType::BOX;
    glm::vec3 size = glm::vec3(1.0f);
    float radius = 0.5f;
    bool isTrigger = false;
};

/**
 * @struct MeshRenderer
 * @brief Renders a 3D mesh
 */
struct MeshRenderer {
    std::string meshPath;
    std::vector<std::string> materialPaths;
    bool castShadows = true;
    bool receiveShadows = true;
};

/**
 * @struct Light
 * @brief Light source
 */
struct Light {
    enum class Type { DIRECTIONAL, POINT, SPOT };
    
    Type type = Type::POINT;
    glm::vec3 color = glm::vec3(1.0f);
    float intensity = 1.0f;
    float range = 10.0f;
    float spotAngle = 45.0f;
};

/**
 * @struct Camera
 * @brief Camera component for rendering
 */
struct Camera {
    float fov = 60.0f;
    float nearPlane = 0.1f;
    float farPlane = 1000.0f;
    bool isPrimary = false;
};

/**
 * @struct AudioSource
 * @brief 3D audio playback
 */
struct AudioSource {
    std::string clipPath;
    float volume = 1.0f;
    float spatialBlend = 1.0f; // 0 = 2D, 1 = 3D
    bool loop = false;
    bool playOnStart = false;
};

/**
 * @struct Animation
 * @brief Character animation
 */
struct Animation {
    std::string clipName;
    float currentTime = 0.0f;
    float playbackSpeed = 1.0f;
    bool isPlaying = false;
    bool loop = true;
};

}
