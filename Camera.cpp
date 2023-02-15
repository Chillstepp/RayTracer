//
// Created by why on 2022/12/28.
//

#include "Camera.h"

Camera::Camera(point3 lookfrom, point3 lookat, vec3 vup/* view up*/,
               double vfov/*vertical field-of-view in degrees*/, double aspect_ratio,
               double aperture/*光圈*/, double focus_dist/*焦距*/)
{
	double facal_length = 1.0;
	double theta = degrees_to_radians(vfov);
    double h = tan(theta/2) * facal_length;
    double viewport_height = 2.0 * h;
    double viewport_width = aspect_ratio * viewport_height;

    w = VecUtilityFunction::unit_vector(lookfrom - lookat);
    u = VecUtilityFunction::unit_vector(VecUtilityFunction::cross(vup, w));
    v = VecUtilityFunction::cross(w,u);

    origin = lookfrom;
    horizontal = focus_dist * viewport_width * u;
    vertical = focus_dist * viewport_height * v;
    lower_left_corner = origin - horizontal/2 - vertical/2 - focus_dist*w;

    lens_radius = aperture/2;
}

Ray Camera::get_ray(double s, double t) const {
    vec3 rd = lens_radius * VecUtilityFunction::random_in_unit_disk();
    vec3 offset = u * rd.x() + v*rd.y();
    return {origin + offset, lower_left_corner + s*horizontal + t*vertical - origin - offset};
}
