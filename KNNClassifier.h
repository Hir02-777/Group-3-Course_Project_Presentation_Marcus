#ifndef KNNCLASSIFIER_H
#define KNNCLASSIFIER_H

#include "Classifier.h"
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <utility>
/**
* @file KNNClassifier.h
* @brief Predicts output based on the k(default: 3) nearest to input in training data.
*/
class KNNClassifier : public Classifier {
private:
	std::vector<DataPoint> trainingData;
	int k;

public:
	KNNClassifier(int k = 3) : k(k) {}

	void train(const std::vector<DataPoint>& data) override {
		trainingData = data;
	}

	std::string predict(const Vector3D& input) override {
		if (trainingData.empty()) {
			return "Unknown";
		}

		std::vector<std::pair<double, std::string>> distances;

		for (const auto& point : trainingData) {
			distances.push_back({ input.distance(point.vec), point.label });
		}

		std::sort(distances.begin(), distances.end(),
			[](const auto& a, const auto& b) {
				return a.first < b.first;
			});

		int limit = std::min(k, static_cast<int>(distances.size()));
		std::unordered_map<std::string, int> votes;

		std::string bestLabel = distances[0].second;
		int bestVotes = 0;

		for (int i = 0; i < limit; i++) {
			int currentVotes = ++votes[distances[i].second];

			if (currentVotes > bestVotes) {
				bestVotes = currentVotes;
				bestLabel = distances[i].second;
			}
		}

		return bestLabel;
	}
};

#endif