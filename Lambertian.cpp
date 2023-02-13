//
// Created by Chillstep on 2023/2/14.
//

#include "Lambertian.h"
#include "VecUtilityFunction.h"
bool Lambertian::Scatter(const Ray& r_in, const hit_record& rec, color& attenuation, Ray& scattered) const
{
	vec3 ScatterDirection = rec.normal + VecUtilityFunction::random_in_unit_sphere();
	//if the ScatterDirection just be zero vec, we will set it to normal direction to prevent the Infinities/NaNs.
	if(ScatterDirection.NearZero())
	{
		ScatterDirection = rec.normal;
	}
	scattered = Ray(rec.p, ScatterDirection);
	attenuation = Albedo;
	return true;
}
