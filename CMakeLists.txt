cmake_minimum_required(VERSION 3.21)
project(RayTracer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static-libstdc++")

INCLUDE_DIRECTORIES(SYSTEM include/)
add_executable(RayTracer main.cpp src/Vector.cpp include/Core/Vector.h include/Core/Color.h src/Ray.cpp include/Core/Ray.h include/Core/configs.h include/Core/Geometry.h include/Core/Sphere.h src/Sphere.cpp include/Core/Scene.h src/Scene.cpp include/utils.h src/Camera.cpp include/Core/Camera.h)
