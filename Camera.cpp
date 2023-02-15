//
// Created by why on 2022/12/28.
//

#include "Camera.h"

Camera::Camera(point3 lookfrom, point3 lookat, vec3 vup/* view up*/,
               double vfov/*vertical field-of-view in degrees*/, double aspect_ratio)
{
	double facal_length = 1.0;
	double theta = degrees_to_radians(vfov);
    double h = tan(theta/2) * facal_length;
    double viewport_height = 2.0 * h;
    double viewport_width = aspect_ratio * viewport_height;

    vec3 w = VecUtilityFunction::unit_vector(lookfrom - lookat);
    vec3 u = VecUtilityFunction::unit_vector(VecUtilityFunction::cross(vup, w));
    vec3 v = VecUtilityFunction::cross(w,u);

    origin = lookfrom;
    horizontal = viewport_width * u;
    vertical = viewport_height * v;
    lower_left_corner = origin - horizontal/2 - vertical/2 - w;
}

Ray Camera::get_ray(double s, double t) const {
    return {origin, lower_left_corner + s*horizontal + t*vertical - origin};
}
