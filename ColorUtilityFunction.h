//
// Created by Chillstep on 2022/12/24.
//

#ifndef RayTracer_COLORUTILITYFUNCTION_H
#define RayTracer_COLORUTILITYFUNCTION_H

#include <iostream>
#include "Ray.h"
#include "Vec.h"

class ColorUtilityFunction
{
public:
    static void write_color(std::ostream &out, color pixel_color) {
        // Write the translated [0,255] value of each color component.
        out << static_cast<int>(255.999 * pixel_color.x()) << ' '
            << static_cast<int>(255.999 * pixel_color.y()) << ' '
            << static_cast<int>(255.999 * pixel_color.z()) << '\n';
    }

    //
    static color ray_color(const Ray& r)
    {
        vec3 UnitDirection = VecUtilityFunction::unit_vector(r.getDir());
        //let UnitDirection.y [-1,1] map to t [0,1]
        auto t = 0.5*(UnitDirection.y() + 1.0);
        //color interpolation
        return (1.0 - t)*color(1.0, 1.0, 1.0) + t*(color(0.5,0.7,1.0));
    }
};


#endif //RayTracer_COLORUTILITYFUNCTION_H
