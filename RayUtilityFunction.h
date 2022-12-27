//
// Created by why on 2022/12/27.
//

#ifndef CPPPRACTICE_RAYUTILITYFUNCTION_H
#define CPPPRACTICE_RAYUTILITYFUNCTION_H

#include "Vec.h"
#include "VecUtilityFunction.h"
#include "Ray.h"

class RayUtilityFunction {
public:
    static double HitSphere(const point3& Centre, double Radius, const Ray& r)
    {
        vec3 oc = r.getOrigin() - Centre;
        auto a = VecUtilityFunction::dot(r.getDir(), r.getDir());
        auto b =2.0*VecUtilityFunction::dot(oc, r.getDir());
        auto c = VecUtilityFunction::dot(oc, oc) - Radius * Radius;
        auto delta = b*b - 4*a*c;
        if(delta<0)
        {
            return -1.0;
        }
        else
        {
            return (-b - sqrt(delta)) / (2.0*a);
        }
    }

    static color ray_color(const Ray& r)
    {
        // t: ray vector = Origin + t * Direction
        auto t = RayUtilityFunction::HitSphere(point3(0,0,-1), 0.5, r);
        //
        if(t>0.0)
        {
            vec3 n = VecUtilityFunction::unit_vector(r.at(t) - vec3(0,0,-1));
            return 0.5*color{n.x()+1,n.y()+1,n.z()+1};
        }
        vec3 UnitDirection = VecUtilityFunction::unit_vector(r.getDir());
        //let UnitDirection.y [-1,1] map to t [0,1]
        t = 0.5*(UnitDirection.y() + 1.0);
        //color interpolation

        return (1.0 - t)*color(1.0, 1.0, 1.0) + t*(color(0.5,0.7,1.0));
    }
};


#endif //CPPPRACTICE_RAYUTILITYFUNCTION_H
