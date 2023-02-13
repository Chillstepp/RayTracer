//
// Created by Chillstep on 2023/2/14.
//

#ifndef RAYTRACER__LAMBERTIAN_H_
#define RAYTRACER__LAMBERTIAN_H_
#include "Material.h"

class Lambertian: public Material
{
 public:
	Lambertian(const color& a): Albedo(a){}
	virtual bool Scatter(const Ray &r_in, const hit_record &rec, color &attenuation, Ray &scattered) const override;
 public:
	//反射率
	color Albedo;
};

#endif //RAYTRACER__LAMBERTIAN_H_
