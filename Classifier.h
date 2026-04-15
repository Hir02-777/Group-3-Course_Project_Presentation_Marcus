#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <vector>
#include <string>
#include "DataPoint.h"

class Classifier {
public:
    virtual void train(const std::vector<DataPoint>& data) = 0;
    virtual std::string predict(const Vector3D& input) = 0;
    virtual ~Classifier() {}
};

#endif