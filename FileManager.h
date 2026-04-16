#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include "DataPoint.h"
/**
* @file FileManager.h
* @brief handles importing and exporting of .txt files
*/
class FileManager {
public:
	/**
	* @brief Loads training data.
	* @param filename The name of target file.
	*/
	static std::vector<DataPoint> loadTrainingData(const std::string& filename);
	/**
	* @brief Loads unknown data.
	* @param filename The name of target file.
	*/
	static std::vector<Vector3D> loadUnknownData(const std::string& filename);
	/**
	* @brief Saves results to .txt file.
	* @param filename The name of target file.
	*/
	static void saveResults(const std::string& filename,
		const std::vector<Vector3D>& inputs,
		const std::vector<std::string>& outputs);
};

#endif