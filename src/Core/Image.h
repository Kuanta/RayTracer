//
// Created by erdem on 8.09.2022.
//

#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H


#include "Vector.h"

namespace Gray
{
    class Image {
    public:
        Image();
        Image(int width, int height);
        void GetPixelValue(int row, int col, int* pixel);
        void SetPixelValue(int row, int col, Vector3 pixelValue);
        void Clear();

    private:
        int* data;

    private:
        int GetOffset(int row, int col); //Offset for 1d data array
    };


}

#endif //RAYTRACER_IMAGE_H
