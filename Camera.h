//
// Created by why on 2022/12/28.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "ConfigAndUtility.h"

class Camera {
public:
    Camera(point3 lookfrom, point3 lookat, vec3 vup, double vfov, double aspect_ratio, double aperture/*光圈*/, double focus_dist/*焦距*/);
    [[nodiscard]] Ray get_ray(double u, double v) const;
private:
    point3 origin;
    point3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
    vec3 u,v,w;
    double lens_radius;
};


#endif //RAYTRACER_CAMERA_H
