cmake_minimum_required(VERSION 3.22)
project(RayTracer)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_STANDARD 20)

add_executable(RayTracer main.cpp
        Vec.cpp Vec.h
        VecUtilityFunction.h
        ColorUtilityFunction.h
        Ray.cpp Ray.h
        Image.cpp Image.h
        RayUtilityFunction.cpp RayUtilityFunction.h
        Hittable.cpp Hittable.h
        Sphere.cpp Sphere.h
        HIttableList.cpp HIttableList.h
        ConfigAndUtility.h
        Camera.cpp Camera.h
        Material.cpp Material.h Lambertian.cpp Lambertian.h Metal.cpp Metal.h)
