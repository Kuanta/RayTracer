//
// Created by erdem on 14.08.2022.
//

#ifndef RAYTRACER_UTILS_H
#define RAYTRACER_UTILS_H

#include <Core/configs.h>
#include <cstdlib>

class RayMath
{
public:
    constexpr static double pi = 3.1415926535897932385;

    static real Random()
    {
        return rand() / (RAND_MAX + 1.0);
    }

    static real Random(real min, real max)

    {
        real randomNormal = RayMath::Random();
        return min + (max - min) * randomNormal;
    }

    static int RandomInt(int min, int max)
    {
        return static_cast<int>(Random(min, max+1));
    }

    inline static real Clamp(real value, real min, real max)
    {
        if(value < min) return min;
        if(value > max) return max;
        return value;
    }

    inline static real DegToRad(real deg)
    {
        return deg * pi / 180.0;
    }

    inline static real RadToDeg(real rad)
    {
        return rad * 180.0 / pi;
    }
};
#endif //RAYTRACER_UTILS_H
