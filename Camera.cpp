//
// Created by why on 2022/12/28.
//

#include "Camera.h"

Camera::Camera() {
    double aspect_ratio = 16.0/9.0;
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double facal_length = 1.0;

    origin = point3(0,0,0);
    horizontal = vec3(viewport_width, 0.0, 0.0);
    vertical = vec3(0.0, viewport_height, 0.0);
    lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0,0,facal_length);
}

Ray Camera::get_ray(double u, double v) const {
    return {origin, lower_left_corner + u*horizontal + v*vertical - origin};
}
