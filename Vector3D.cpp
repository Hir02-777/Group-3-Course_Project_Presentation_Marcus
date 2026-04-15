#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

double Vector3D::distance(const Vector3D& other) const {
    return sqrt(pow(x - other.x, 2) +
        pow(y - other.y, 2) +
        pow(z - other.z, 2));
}