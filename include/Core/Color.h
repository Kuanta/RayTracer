#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include <utils.h>
#include "Vector.h"

void write_color(std::ostream &out, Color pixel_color, int samplesPerPixel) {

    real red = pixel_color.x;
    real green = pixel_color.y;
    real blue = pixel_color.z;

    real scale = 1.0 / samplesPerPixel;

    red *= scale;
    green *= scale;
    blue *= scale;

    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(256 * RayMath::Clamp(red, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * RayMath::Clamp(green, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * RayMath::Clamp(blue, 0.0, 0.999)) << '\n';
}

#endif //RAYTRACER_COLOR_H
