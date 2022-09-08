//
// Created by erdem on 8.09.2022.
//

#include "Image.h"
using namespace Gray;

Image::Image() {
    data = nullptr;
}
Image::Image(int width, int height) {
    data = new int[width*height]();
    for(int r=0;r<height;++r)
    {
        for(int c=0;c<width;++c)
        {
            SetPixelValue(r, c, Vector3(0,0,0));
        }
    }
}

void Image::Clear() {
    if(data != nullptr)
    {
        delete data;
    }
}

void Image::SetPixelValue(int row, int col, Vector3 pixelValue) {
    if(data == nullptr) return;
    int offset = GetOffset(row, col);
    data[offset] = pixelValue.x;
    data[offset + 1] = pixelValue.y;
    data[offset + 2] = pixelValue.z;
}

void Image::GetPixelValue(int row, int col, int* pixel){
    if(data == nullptr) return;
    int offset = GetOffset(row, col);
    pixel[0] = data[offset];
    pixel[1] = data[offset+1];
    pixel[2]= data[offset+2];
}

int Image::GetOffset(int row, int col)
{
    return row*col + col;
}

