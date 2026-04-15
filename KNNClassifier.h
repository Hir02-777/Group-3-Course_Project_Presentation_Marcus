#ifndef KNNCLASSIFIER_H
#define KNNCLASSIFIER_H

#include "Classifier.h"
#include <iostream>

class KNNClassifier : public Classifier {
public:
    void train(const std::vector<DataPoint>&) override {
        std::cout << "KNNClassifier::train()\n";
    }

    std::string predict(const Vector3D&) override {
        std::cout << "Not implemented yet\n";
        return "N/A";
    }
};

#endif