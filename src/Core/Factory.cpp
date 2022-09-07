//
// Created by erdem on 7.09.2022.
//

#include "Factory.h"
#include "Sphere.h"

Mesh Factory::CreateSphereMesh(Vector3 position, float radius) {
    Sphere* sphereGeo;
    sphereGeo = new Sphere(radius);
    Material* sphereMat = new Material();
    Mesh mesh(sphereGeo, sphereMat);
    mesh.position = position;
    return mesh;
}
