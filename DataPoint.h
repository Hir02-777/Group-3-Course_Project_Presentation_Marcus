#ifndef DATAPOINT_H
#define DATAPOINT_H

#include "Vector3D.h"
#include <string>

class DataPoint {
public:
    Vector3D vec;
    std::string label;

    DataPoint(Vector3D v, std::string l);
};

#endif