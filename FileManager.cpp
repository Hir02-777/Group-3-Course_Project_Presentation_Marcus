#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
std::vector<DataPoint> FileManager::loadTrainingData(const std::string& filename) {
	std::vector<DataPoint> data;
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cout << "FAILED TO OPEN TRAINING FILE: " << filename << std::endl;
		return data;
	}

	std::string line;

	while (std::getline(file, line)) {
		if (line.empty()) continue;

		std::replace(line.begin(), line.end(), ',', ' ');

		std::stringstream ss(line);
		double x, y, z;
		std::string label;

		if (ss >> x >> y >> z >> label) {
			data.emplace_back(Vector3D(x, y, z), label);
		}
	}

	return data;
}

std::vector<Vector3D> FileManager::loadUnknownData(const std::string& filename) {
	std::vector<Vector3D> data;
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cout << "FAILED TO OPEN FILE: " << filename << std::endl;
		return data;
	}

	std::string line;

	while (std::getline(file, line)) {
		if (line.empty()) continue;

		std::replace(line.begin(), line.end(), ',', ' ');

		std::stringstream ss(line);
		double x, y, z;

		if (ss >> x >> y >> z) {
			data.emplace_back(x, y, z);
		}
	}

	return data;
}

void FileManager::saveResults(const std::string& filename,
	const std::vector<Vector3D>& inputs,
	const std::vector<std::string>& outputs) {
	std::ofstream file(filename);

	if (!file.is_open()) {
		std::cout << "FAILED TO CREATE RESULT FILE: " << filename << std::endl;
		return;
	}

	for (size_t i = 0; i < inputs.size() && i < outputs.size(); i++) {
		file << inputs[i].x << " "
			<< inputs[i].y << " "
			<< inputs[i].z << " -> "
			<< outputs[i] << "\n";
	}
}