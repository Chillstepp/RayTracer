//
// Created by Chillstep on 2023/2/14.
//

#include "Metal.h"

bool Metal::Scatter(const Ray& r_in, const hit_record& rec, color& attenuation, Ray& scattered) const
{
	vec3 ReflectedDir = VecUtilityFunction::Reflect(VecUtilityFunction::unit_vector(r_in.getDir()), rec.normal);
	//The bigger the Fuzz, the fuzzier the reflections will be
	scattered = Ray{rec.p, ReflectedDir + Fuzz*VecUtilityFunction::random_in_unit_sphere()};
	attenuation = Albedo;

	return (VecUtilityFunction::dot(scattered.getDir(), rec.normal) > 0);
}
