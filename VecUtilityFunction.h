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

	inline static vec3 random_in_unit_sphere()
    {
        while(true)
        {
            vec3 p = random(-1, 1);
            if(p.LengthSquared() >= 1) continue;
            return p;
        }
    }

	inline static vec3 random_unit_vector() {
		return unit_vector(random_in_unit_sphere());
	}
	//Related derivation see: https://raytracing.github.io/books/RayTracingInOneWeekend.html#metal/mirroredlightreflection for details
	inline static vec3 Reflect(const vec3& v, const vec3& n)
	{
		return v - 2 * dot(v,n) * n;
	}

	//Related derivation see: https://raytracing.github.io/books/RayTracingInOneWeekend.html#dielectrics/snell'slaw
	inline static vec3 Refract(const vec3& ray_in, const vec3& n, double etai_over_etat){
		//we want to assure that the ray_in is unit vector
		vec3 ray_in_unit = VecUtilityFunction::unit_vector(ray_in);
		//we auusre that n(normal) is unit vector
		double cos_theta = std::min(VecUtilityFunction::dot(-ray_in_unit, n), 1.0);
		vec3 r_out_perpendicular = etai_over_etat*(ray_in_unit + cos_theta*n);
		vec3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perpendicular.LengthSquared()))*n;
		return r_out_parallel + r_out_perpendicular;
	}
};
#endif //RayTracer_VECUTILITYFUNCTION_H
