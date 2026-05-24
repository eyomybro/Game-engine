#pragma once

#include "engine/ecs/system.h"
#include "engine/ai/behavior/behavior_tree.h"
#include <glm/glm.hpp>
#include <vector>

namespace Engine::AI {

/**
 * @struct AIAgent
 * @brief Component for AI-controlled entities
 */
struct AIAgent {
    enum class AIType { PATROL, PURSUIT, COMBAT, WANDERING };
    
    AIType aiType = AIType::PATROL;
    std::shared_ptr<BehaviorTree> behaviorTree;
    float sightRange = 20.0f;
    float attackRange = 2.0f;
    bool canSeek = true;
    bool canPatrol = true;
};

/**
 * @struct Perception
 * @brief Component for NPC perception and awareness
 */
struct Perception {
    // Vision
    float visionRange = 30.0f;
    float visionAngle = 120.0f; // degrees
    std::vector<ECS::EntityID> visibleTargets;
    
    // Hearing
    float hearingRange = 50.0f;
    std::vector<glm::vec3> heardSounds;
    
    // Memory
    struct Memory {
        ECS::EntityID entityId;
        glm::vec3 lastSeenPosition;
        float timeRemembered = 0.0f;
        float maxMemoryDuration = 5.0f;
    };
    std::vector<Memory> memories;
};

/**
 * @struct StateMachine
 * @brief Component for hierarchical state machines
 */
struct StateMachine {
    enum class State { IDLE, PATROL, PURSUE, ATTACK, FLEE, DEAD };
    
    State currentState = State::IDLE;
    State previousState = State::IDLE;
    float stateTime = 0.0f;
};

/**
 * @struct NavMeshAgent
 * @brief Component for pathfinding on navigation mesh
 */
struct NavMeshAgent {
    std::vector<glm::vec3> currentPath;
    size_t pathIndex = 0;
    glm::vec3 targetPosition = glm::vec3(0.0f);
    float stoppingDistance = 0.5f;
    float speed = 5.0f;
    bool hasPath = false;
};

}
