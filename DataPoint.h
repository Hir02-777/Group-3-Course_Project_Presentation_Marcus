#ifndef DATAPOINT_H
#define DATAPOINT_H

#include "Vector3D.h"
#include <string>
/**
* @file Datapoint.h
*  @brief A training data point, contains both the vector and its associated orientation
*/
class DataPoint {
public:
	Vector3D vec;
	std::string label;
	DataPoint(Vector3D v, std::string l);
};

#endif