#ifndef NNCLASSIFIER_H
#define NNCLASSIFIER_H

#include "Classifier.h"

class NNClassifier : public Classifier {
private:
    std::vector<DataPoint> trainingData;

public:
    void train(const std::vector<DataPoint>& data) override;
    std::string predict(const Vector3D& input) override;
};

#endif