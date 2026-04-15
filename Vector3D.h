#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {
public:
    double x, y, z;

    Vector3D(double x = 0, double y = 0, double z = 0);
    double distance(const Vector3D& other) const;
};

#endif