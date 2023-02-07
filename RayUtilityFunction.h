//
// Created by why on 2022/12/27.
//

#ifndef CPPPRACTICE_RAYUTILITYFUNCTION_H
#define CPPPRACTICE_RAYUTILITYFUNCTION_H

#include "Vec.h"
#include "VecUtilityFunction.h"
#include "Ray.h"
#include "ConfigAndUtility.h"
#include "HIttableList.h"

class RayUtilityFunction {
public:
    static double HitSphere(const point3& Centre, double Radius, const Ray& r)
    {
        vec3 oc = r.getOrigin() - Centre;
        auto a = VecUtilityFunction::dot(r.getDir(), r.getDir());
        auto half_b = VecUtilityFunction::dot(oc, r.getDir());
        auto c = VecUtilityFunction::dot(oc, oc) - Radius * Radius;
        auto delta = half_b*half_b - a*c;
        if(delta<0)
        {
            return -1.0;
        }
        else
        {
            return (-half_b - sqrt(delta)) / a;
        }
    }

    static color ray_color(const Ray& r, Hittable& world, int Depth)
    {
        hit_record record;
        if(Depth <= 0)
        {
            return color(0,0,0);
        }
        if(world.hit(r, 0.001, infinity,record))
        {
            point3 target = record.p + record.normal + VecUtilityFunction::random_in_unit_sphere();
            return 0.5 * ray_color(Ray{record.p, target - record.p}, world, Depth-1);
        }
        vec3 UnitDirection = VecUtilityFunction::unit_vector(r.getDir());
        //let UnitDirection.y [-1,1] map to t [0,1]
        double t = 0.5*(UnitDirection.y() + 1.0);
        //color interpolation
        return (1.0 - t)*color(1.0, 1.0, 1.0) + t*(color(0.5,0.7,1.0));
    }
};


#endif //CPPPRACTICE_RAYUTILITYFUNCTION_H
