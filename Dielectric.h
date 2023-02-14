//
// Created by Chillstep on 2023/2/14.
//

#ifndef RAYTRACER__DIELECTRIC_H_
#define RAYTRACER__DIELECTRIC_H_
#include "Material.h"

class Dielectric: public Material
{
 public:
	Dielectric(const double ir):ir(ir){}
	virtual bool Scatter(const Ray &r_in, const hit_record &rec, color &attenuation, Ray &scattered) const override;
 public:
	// 折射率 Index of Refraction
	double ir;
 private:
	// Use Schlick's approximation for reflectance.
	// get ir from different angle.
	static double reflectance(double cos, double ir){
		double r0 = (1-ir)/(1+ir);
		r0 = r0*r0;
		return r0 + (1 - r0)* pow((1-cos), 5);
	}
};

#endif //RAYTRACER__DIELECTRIC_H_
