cmake_minimum_required(VERSION 3.23)
project(RayTracer)

set(CMAKE_CXX_STANDARD 20)

add_executable(RayTracer main.cpp Vec.cpp Vec.h VecUtilityFunction.h ColorUtilityFunction.h Ray.cpp Ray.h Image.cpp Image.h)
