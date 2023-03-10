//
// Created by Chillstep on 2022/12/27.
//

#ifndef RAYTRACER_CONFIGANDUTILITY_H
#define RAYTRACER_CONFIGANDUTILITY_H

#include <cmath>
#include <limits>
#include <memory>
#include <random>


// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

constexpr double infinity = std::numeric_limits<double>::infinity();
constexpr double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double();
}


template<typename T>
T clamp(const T& val,const T& min,const T& max)
{
    if (val < min) return min;
    if (val > max) return max;
    return val;
}

// Common Headers
#include "Ray.h"
#include "Vec.h"


#endif //RAYTRACER_CONFIGANDUTILITY_H
