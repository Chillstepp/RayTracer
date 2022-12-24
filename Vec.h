//
// Created by Chillstep on 2022/12/24.
//

#ifndef RayTracer_VEC_H
#define RayTracer_VEC_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
public:
    vec3():e{0,0,0}{};
    vec3(double e0, double e1, double e2): e{e0,e1,e2}{};

    [[nodiscard]] inline double x() const {return e[0];}
    [[nodiscard]] inline double y() const {return e[1];}
    [[nodiscard]] inline double z() const {return e[2];}

    vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]);}
    double operator[](int i) const
    {
        if(i<0 or i>=3) std::cerr << "double operator[](int i): const idx error \n";
        else return e[i];
    }

    double& operator[](int i)
    {
        if(i<0 or i>=3) std::cerr << "double operator[](int i): const idx error \n";
        else return e[i];
    }

    vec3& operator+=(const vec3& v)
    {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    vec3& operator-=(const vec3& v)
    {
        *this += (-v);
        return *this;
    }

    vec3& operator*=(const double t)
    {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec3& operator/=(const double t)
    {
        e[0] /= t;
        e[1] /= t;
        e[2] /= t;
        return *this;
    }

    [[nodiscard]] double LengthSquared() const
    {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

    [[nodiscard]] double Length() const
    {
        return sqrt(LengthSquared());
    }

public:
    double e[3];
};

using point3 = vec3;
using color = vec3;

#endif //RayTracer_VEC_H
