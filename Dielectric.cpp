//
// Created by Chillstep on 2023/2/14.
//

#include "Dielectric.h"
bool Dielectric::Scatter(const Ray& r_in, const hit_record& rec, color& attenuation, Ray& scattered) const
{
	attenuation = color(1.0, 1.0, 1.0);
	double refraction_ratio = rec.front_face ? (1.0/ir) : ir;
	vec3 unit_direction = VecUtilityFunction::unit_vector(r_in.getDir());
	//some times the Snell's law may occur to sin(\theta prime) may > 1, which means that
	// the glass cannot refract, and therefore must reflect the ray:
	double cos_theta = std::fmin(VecUtilityFunction::dot(-unit_direction, rec.normal), 1.0);
	double sin_theta = sqrt(1 - cos_theta*cos_theta);
	bool cannot_refract = refraction_ratio * sin_theta > 1.0;
	//There is also a truth that  real glass has reflectivity that varies with angle
	// for example: look at a window at a steep angle and it becomes a mirror.
	// we don't want a big ugly equation for that, so let's use  a cheap and surprisingly
	// accurate polynomial approximation by Christophe Schlick just like almost all people.
	if(cannot_refract || reflectance(cos_theta, refraction_ratio) > random_double())
	{
		vec3 reflected = VecUtilityFunction::Reflect(unit_direction, rec.normal);
		scattered = Ray{rec.p, reflected};
	}
	else
	{
		vec3 refracted = VecUtilityFunction::Refract(unit_direction, rec.normal, refraction_ratio);
		scattered = Ray{rec.p, refracted};
	}
	return true;
}
