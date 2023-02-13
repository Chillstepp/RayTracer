//
// Created by Chillstep on 2022/12/27.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "hittable.h"
#include "Vec.h"

class Sphere: public Hittable{
public:
    Sphere() = default;
    Sphere(point3 center, double r, shared_ptr<Material>m):Center(center), Radius(r), MaterialPtr(m){}
    virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override;
public:
    point3 Center;
    double Radius;
	shared_ptr<Material>MaterialPtr;
};


#endif //RAYTRACER_SPHERE_H
