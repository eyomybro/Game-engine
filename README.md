# Advanced Game Engine

A professional-grade, production-ready game engine built in C++ for developing AAA-quality games with advanced AI, physics, rendering, and real-time performance.

## Core Features

### Architecture
- **Entity-Component-System (ECS)**: Flexible, data-driven design
- **Game Loop**: Fixed timestep, frame pacing, performance metrics
- **Scene Management**: Hierarchical scenes with culling
- **Asset Pipeline**: Streaming, caching, lifecycle management

### Rendering System
- **3D Graphics Pipeline**: OpenGL/Vulkan abstraction
- **Material System**: PBR (Physically Based Rendering)
- **Lighting**: Real-time, deferred rendering, shadows
- **Post-Processing**: Bloom, SSAO, Motion Blur
- **Particle System**: GPU-driven effects

### Physics Engine
- **Rigid Body Dynamics**: Full 3D physics simulation
- **Collision Detection**: Spatial partitioning, broad/narrow phase
- **Constraints**: Joints, hinges, springs
- **Raycasting**: Fast geometric queries

### AI Systems
- **Pathfinding**: A* with navigation meshes
- **Behavior Trees**: Composable, reusable AI behaviors
- **State Machines**: Hierarchical FSM
- **GOAP**: Goal-Oriented Action Planning
- **Perception**: Vision cones, hearing, memory

### Audio System
- **3D Positional Audio**: Spatial sound
- **Mixing**: Multiple sources with effects
- **Streaming**: Efficient memory management

## Getting Started

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
```

## Build Requirements
- C++17 or later
- CMake 3.16+
- OpenGL 4.6 / Vulkan 1.2

## License

MIT - See LICENSE file
