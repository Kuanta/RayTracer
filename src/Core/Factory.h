//
// Created by erdem on 7.09.2022.
//

#ifndef RAYTRACER_FACTORY_H
#define RAYTRACER_FACTORY_H


#include "Mesh.h"

class Factory {
public:
    static Mesh CreateSphereMesh(Vector3 position, float radius);
};


#endif //RAYTRACER_FACTORY_H
