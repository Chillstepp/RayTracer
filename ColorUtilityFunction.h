//
// Created by Chillstep on 2022/12/24.
//

#ifndef RayTracer_COLORUTILITYFUNCTION_H
#define RayTracer_COLORUTILITYFUNCTION_H

#include <iostream>
#include "Vec.h"

void write_color(std::ostream &out, color pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}


#endif //RayTracer_COLORUTILITYFUNCTION_H
