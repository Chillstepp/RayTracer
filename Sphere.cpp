//
// Created by Chillstep on 2022/12/27.
//

#include "Sphere.h"

bool Sphere::hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    vec3 oc = r.getOrigin() - Center;
    double a = VecUtilityFunction::dot(r.getDir(), r.getDir());
    double half_b = VecUtilityFunction::dot(oc, r.getDir());
    double c = VecUtilityFunction::dot(oc, oc) - Radius * Radius;
    double discriminant = half_b*half_b - a*c;

    if(discriminant<0) return false;

    double root = (-half_b - sqrt(discriminant)) / a;
    if(root < t_min or t_max < root)
    {
        root = (-half_b + sqrt(discriminant)) / a;
        if(root < t_min or t_max < root)
        {
            return false;
        }
    }
    rec.t = root;
    rec.p = r.at(root);
    rec.normal = (rec.p - Center) / Radius;
    return true;
}
