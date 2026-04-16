#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <vector>
#include <string>
#include "DataPoint.h"
/**
* @file Classifier.h
* @brief define an abstract class for all classifiers.
*/
class Classifier {
public:
	/**
	* @brief create training data for referencing in classifier
	* @param A array of vector points and matching labels
	*/
	virtual void train(const std::vector<DataPoint>& data) = 0;
	/**
	* @brief Abstract. predict the orientation of the phone based on the given vector.
	* @param input A 3d point vector
	* @returns Orientation of the phone
	*/
	virtual std::string predict(const Vector3D& input) = 0;
	/// 
	virtual ~Classifier() {}
};

#endif