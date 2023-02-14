//
// Created by Chillstep on 2023/2/14.
//

#ifndef RAYTRACER__METAL_H_
#define RAYTRACER__METAL_H_
#include "Material.h"

class Metal: public Material
{
 public:
	Metal(const color& a, const double& f): Albedo(a), Fuzz(f < 1 ? f : 1){}
	virtual bool Scatter(const Ray &r_in, const hit_record &rec, color &attenuation, Ray &scattered) const override;

 public:
	//material color
	color Albedo;
	//Fuzzy Reflection, this parameter is used to roughen the surface
	double Fuzz;
};

#endif //RAYTRACER__METAL_H_
