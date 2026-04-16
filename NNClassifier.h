#ifndef NNCLASSIFIER_H
#define NNCLASSIFIER_H

#include "Classifier.h"
/**
* @file NNClassifier.h
* @brief predicts output by finding nearest input in training data
*/
class NNClassifier : public Classifier {
private:
	std::vector<DataPoint> trainingData;

public:
	void train(const std::vector<DataPoint>& data) override;
	std::string predict(const Vector3D& input) override;
};

#endif