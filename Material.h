//
// Created by Chillstep on 2023/2/14.
//

#ifndef RAYTRACER__MATERIAL_H_
#define RAYTRACER__MATERIAL_H_

#include "Ray.h"
#include "Hittable.h"

class Material
{
 public:
	virtual bool Scatter(const Ray& r_in, const hit_record& rec, color& attenuation,Ray& scattered) const = 0;
};

#endif //RAYTRACER__MATERIAL_H_
