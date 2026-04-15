#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include "DataPoint.h"

class FileManager {
public:
    static std::vector<DataPoint> loadTrainingData(const std::string& filename);
    static std::vector<Vector3D> loadUnknownData(const std::string& filename);
    static void saveResults(const std::string& filename,
        const std::vector<Vector3D>& inputs,
        const std::vector<std::string>& outputs);
};

#endif