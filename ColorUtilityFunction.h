//
// Created by Chillstep on 2022/12/24.
//

#ifndef RayTracer_COLORUTILITYFUNCTION_H
#define RayTracer_COLORUTILITYFUNCTION_H

#include <iostream>
#include "Ray.h"
#include "Vec.h"
#include <cassert>
#include "ConfigAndUtility.h"

class ColorUtilityFunction
{
public:
    static void write_color(std::ostream &out, color pixel_color, int samples_per_pixel) {
        assert(samples_per_pixel!=0);

        double r = pixel_color.x();
        double g = pixel_color.y();
        double b = pixel_color.z();

        double scale = 1.0 / samples_per_pixel;
        r *= scale;
        g *= scale;
        b *= scale;

        // Write the translated [0,255] value of each color component.
        out << static_cast<int>(255.999 * clamp(r, 0.0, 1.0)) << ' '
            << static_cast<int>(255.999 * clamp(g, 0.0, 1.0)) << ' '
            << static_cast<int>(255.999 * clamp(b, 0.0, 1.0)) << '\n';
    }

    //
};


#endif //RayTracer_COLORUTILITYFUNCTION_H
