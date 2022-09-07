cmake_minimum_required(VERSION 3.21)
project(RayTracer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static-libstdc++")

INCLUDE_DIRECTORIES(SYSTEM src/)
add_executable(RayTracer main.cpp src/Core/Vector.cpp src/Core/Vector.h src/Core/Color.h src/Core/Ray.cpp src/Core/Ray.h src/Core/configs.h src/Core/Geometry.h src/Core/Sphere.h src/Core/Sphere.cpp src/Core/Scene.h src/Core/Scene.cpp src/utils.h src/Core/Camera.cpp src/Core/Camera.h src/Core/Material.h src/Core/Mesh.cpp src/Core/Mesh.h src/Core/Factory.cpp src/Core/Factory.h src/Core/HitPoint.h src/Materials/Lambertian.cpp src/Materials/Lambertian.h src/Materials/MetalicMaterial.cpp src/Materials/MetalicMaterial.h)
