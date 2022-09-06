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
    inline static real Random()
    {
        return rand() / (RAND_MAX + 1.0);
    }

    inline static real Random(real min, real max)

    {
        real randomNormal = RayMath::Random();
        return min + (max - min) * randomNormal;
    }

    inline static real Clamp(real value, real min, real max)
    {
        if(value < min) return min;
        if(value > max) return max;
        return value;
    }
};
#endif //RAYTRACER_UTILS_H
