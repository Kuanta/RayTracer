//
// Created by erdem on 7.09.2022.
//

#include <Materials/Lambertian.h>
#include "Factory.h"
#include "Sphere.h"

Mesh* Factory::CreateSphereMesh(Vector3 position, float radius, Vector3 color) {
    Sphere* sphereGeo;
    sphereGeo = new Sphere(radius);
    Material* sphereMat = new Lambertian(color);
    sphereMat->Color = color;
    Mesh* mesh = new Mesh(sphereGeo, sphereMat);
    mesh->position = position;
    return mesh;
}

Mesh* Factory::CreateSphereMesh(Vector3 position, float radius, Material* material)
{
    Sphere* sphereGeo;
    sphereGeo = new Sphere(radius);
    Material* sphereMat = material;
    Mesh* mesh = new Mesh(sphereGeo, sphereMat);
    mesh->position = position;
    return mesh;
}
