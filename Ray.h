//
// Created by Chillstep on 2022/12/25.
//

#ifndef RayTracer_RAY_H
#define RayTracer_RAY_H

#include "Vec.h"
#include "VecUtilityFunction.h"
class Ray {
public:
    Ray() = default;
    Ray(const point3& Origin,const vec3& Direction): Origin(Origin), Direction(Direction){}

    [[nodiscard]] point3 getOrigin() const {return Origin;}
    [[nodiscard]] point3 getDir() const {return Direction;}

    [[nodiscard]] point3 at(double t) const
    {
        return Origin + t * Direction;
    }
public:
    point3 Origin;
    vec3 Direction;
};


#endif //RayTracer_RAY_H
