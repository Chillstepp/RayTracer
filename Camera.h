//
// Created by why on 2022/12/28.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "ConfigAndUtility.h"

class Camera {
public:
    Camera();
    [[nodiscard]] Ray get_ray(double u, double v) const;
private:
    point3 origin;
    point3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
};


#endif //RAYTRACER_CAMERA_H
