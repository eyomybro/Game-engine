#pragma once

#include "engine/ecs/system.h"
#include <glm/glm.hpp>

namespace Engine::Systems {

/**
 * @class PhysicsSystem
 * @brief Updates physics for all rigid bodies
 */
class PhysicsSystem : public ECS::System {
public:
    void onUpdate(float deltaTime) override;
    
private:
    void integrateForces(float deltaTime);
    void resolveCollisions();
    void updateTransforms();
};

/**
 * @class AISystem
 * @brief Updates AI behavior for all agents
 */
class AISystem : public ECS::System {
public:
    void onUpdate(float deltaTime) override;
    
private:
    void updatePerception(float deltaTime);
    void updateBehavior(float deltaTime);
    void updatePathfinding(float deltaTime);
};

/**
 * @class RenderSystem
 * @brief Renders all visible entities
 */
class RenderSystem : public ECS::System {
public:
    void onUpdate(float deltaTime) override;
    
private:
    void frustumCulling();
    void sortByMaterial();
    void submitRenderCommands();
};

/**
 * @class AnimationSystem
 * @brief Updates skeletal animations
 */
class AnimationSystem : public ECS::System {
public:
    void onUpdate(float deltaTime) override;
    
private:
    void updateAnimationStates(float deltaTime);
    void blendAnimations();
};

/**
 * @class AudioSystem
 * @brief Updates 3D audio positions and playback
 */
class AudioSystem : public ECS::System {
public:
    void onUpdate(float deltaTime) override;
    
private:
    void update3DAudio();
    void updateListenerPosition();
};

/**
 * @class InputSystem
 * @brief Handles player input and converts to actions
 */
class InputSystem : public ECS::System {
public:
    void onUpdate(float deltaTime) override;
    
private:
    void pollInputDevices();
    void updatePlayerController();
};

}
