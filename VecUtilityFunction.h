//
// Created by Chillstep on 2022/12/24.
//

#ifndef RayTracer_VECUTILITYFUNCTION_H
#define RayTracer_VECUTILITYFUNCTION_H

#include "Vec.h"
#include "ConfigAndUtility.h"


class VecUtilityFunction
{
public:
    static double dot(const vec3 &u, const vec3 &v) {
        return  u.e[0] * v.e[0]
                + u.e[1] * v.e[1]
                + u.e[2] * v.e[2];
    }

    static vec3 cross(const vec3 &u, const vec3 &v) {
        return {u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]};
    }

    static vec3 unit_vector(vec3 v) {
        return v / v.Length();
    }

    inline static vec3 random(){
        return {random_double(), random_double(), random_double()};
    }

    inline static vec3 random(double min, double max){
        return {random_double(min, max), random_double(min, max), random_double(min, max)};
    }

    static inline vec3 random_in_unit_sphere()
    {
        while(true)
        {
            vec3 p = random(-1, 1);
            if(p.LengthSquared() >= 1) continue;
            return p;
        }
    }
};
#endif //RayTracer_VECUTILITYFUNCTION_H
