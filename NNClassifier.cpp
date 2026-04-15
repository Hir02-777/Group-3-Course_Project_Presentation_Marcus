#include "NNClassifier.h"

void NNClassifier::train(const std::vector<DataPoint>& data) {
    trainingData = data;
}

std::string NNClassifier::predict(const Vector3D& input) {
    double minDist = 1e9;
    std::string bestLabel = "Unknown";

    for (const auto& point : trainingData) {
        double dist = input.distance(point.vec);
        if (dist < minDist) {
            minDist = dist;
            bestLabel = point.label;
        }
    }
    return bestLabel;
}