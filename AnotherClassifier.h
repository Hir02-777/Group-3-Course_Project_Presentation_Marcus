#ifndef ANOTHERCLASSIFIER_H
#define ANOTHERCLASSIFIER_H

#include "Classifier.h"
#include <iostream>

class AnotherClassifier : public Classifier {
public:
    void train(const std::vector<DataPoint>&) override {
        std::cout << "AnotherClassifier::train()\n";
    }

    std::string predict(const Vector3D&) override {
        std::cout << "Not implemented yet\n";
        return "N/A";
    }
};

#endif