#include <iostream>
#include "NNClassifier.h"
#include "AnotherClassifier.h"
#include "KNNClassifier.h"
#include "FileManager.h"

int main() {
    int choice;
    std::cout << "1. NNClassifier\n2. AnotherClassifier\n3. KNNClassifier\n";
    std::cin >> choice;

    Classifier* clf = nullptr;

    if (choice == 1) clf = new NNClassifier();
    else if (choice == 2) clf = new AnotherClassifier();
    else if (choice == 3) clf = new KNNClassifier();
    else {
        std::cout << "Invalid choice\n";
        return 0;
    }

    if (choice != 1) {
        std::cout << "This classifier is not implemented yet.\n";
        delete clf;
        return 0;
    }

    auto trainingData = FileManager::loadTrainingData("trainingData.txt");
    clf->train(trainingData);

    int option;
    std::cout << "1. Manual input\n2. File input\n";
    std::cin >> option;

    if (option == 1) {
        double x, y, z;
        std::cin >> x >> y >> z;

        if (x < -1 || x > 1 || y < -1 || y > 1 || z < -1 || z > 1) {
            std::cout << "Invalid input\n";
        }
        else {
            std::cout << "Orientation: "
                << clf->predict(Vector3D(x, y, z)) << "\n";
        }
    }
    else if (option == 2) {
        std::string filename;
        std::cin >> filename;

        auto inputs = FileManager::loadUnknownData(filename);
        std::cout << "Loaded points: " << inputs.size() << std::endl;
        std::vector<std::string> outputs;

        for (auto& v : inputs) {
            outputs.push_back(clf->predict(v));
        }

        FileManager::saveResults("result.txt", inputs, outputs);
        std::cout << "Saved to result.txt\n";
    }

    delete clf;
    return 0;
}   