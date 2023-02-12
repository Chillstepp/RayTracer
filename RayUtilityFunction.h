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
            return color{0,0,0};
        }
		//[why]: 球面粉刺问题，从球面反射的光不应该给球面自身造成阴影。
		//为什么会出来黑点点？
		// 1. 主要是因为 每次衰减一半，衰减到最后就颜色就成黑色了
		// 2. r是个反射光，他的起点可能因为误差并正好在圆表面上，而也可能在内部/外部很近的地方，如果是圆内很近的地方，t=0会发现永远会和圆表面有交点，导致光线很难出来，这也是运行慢的原因。
		// 解决方法: 很简单我们把从内部射出的光纤和表面接触的点排除即可，即t = 0.01 以上再计算相交即可。
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
