#ifndef ANOTHERCLASSIFIER_H
#define ANOTHERCLASSIFIER_H

#include "Classifier.h"
#include <map>
#include <string>
#include <vector>

class AnotherClassifier : public Classifier {
private:
    std::map<std::string, Vector3D> centroids;

public:
    void train(const std::vector<DataPoint>& data) override {
        centroids.clear();

        std::map<std::string, double> sumX;
        std::map<std::string, double> sumY;
        std::map<std::string, double> sumZ;
        std::map<std::string, int> counts;

        for (const auto& point : data) {
            sumX[point.label] += point.vec.x;
            sumY[point.label] += point.vec.y;
            sumZ[point.label] += point.vec.z;
            counts[point.label]++;
        }

        for (const auto& entry : counts) {
            const std::string& label = entry.first;
            int count = entry.second;

            centroids[label] = Vector3D(
                sumX[label] / count,
                sumY[label] / count,
                sumZ[label] / count
            );
        }
    }

    std::string predict(const Vector3D& input) override {
        if (centroids.empty()) {
            return "Unknown";
        }

        double minDist = 1e9;
        std::string bestLabel = "Unknown";

        for (const auto& entry : centroids) {
            double dist = input.distance(entry.second);

            if (dist < minDist) {
                minDist = dist;
                bestLabel = entry.first;
            }
        }

        return bestLabel;
    }
};

#endif