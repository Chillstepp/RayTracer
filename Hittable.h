//
// Created by Chillstep on 2022/12/27.
//

#ifndef RAYTRACER_HITTABLE_H
#define RAYTRACER_HITTABLE_H

#include "Ray.h"
#include "VecUtilityFunction.h"

struct hit_record
{
    point3 p;
    vec3 normal;
    //hit times
    double t;

    //judge the ray is from inside/outside the sphere
    bool front_face;
    inline void set_face_normal(const Ray& r, const vec3& outward_normal) {
        front_face = VecUtilityFunction::dot(r.getDir(), outward_normal) < 0;
        normal = front_face ? outward_normal :-outward_normal;
    }
};


class Hittable {
public:
    virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};


#endif //RAYTRACER_HITTABLE_H
