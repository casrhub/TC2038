#include "KMPMatcher.h"
#include <iostream>
#include <fstream>
#include <string>

// Function to read file content into a string
std::string readFileContent(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return "";
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

int main() {
    // File names for transmission and mcode files
    std::string transmissionFiles[] = {"transmission1.txt", "transmission2.txt"};
    std::string mcodeFiles[] = {"mcode1.txt", "mcode2.txt", "mcode3.txt"};

    // Loop through each transmission file and mcode file combination
    for (const std::string& transmissionFile : transmissionFiles) {
        std::string transmissionContent = readFileContent(transmissionFile);

        if (transmissionContent.empty()) {
            std::cerr << "Transmission file is empty or couldn't be read." << std::endl;
            continue;
        }

        for (const std::string& mcodeFile : mcodeFiles) {
            std::string mcodeContent = readFileContent(mcodeFile);

            if (mcodeContent.empty()) {
                std::cerr << "Mcode file is empty or couldn't be read." << std::endl;
                continue;
            }

            // Variable to hold the index of where the pattern is found
            int index = -1;

            // Use KMPSearch to check if the mcode is found in the transmission file
            bool result = KMPSearch(transmissionContent, mcodeContent, index);

            // Print the result and the index where the pattern was found
            if (result) {
                std::cout << "true: the pattern \"" << mcodeContent
                          << "\" from " << mcodeFile
                          << " was found at index " << index
                          << " in " << transmissionFile << std::endl;
            } else {
                std::cout << "false: the pattern \"" << mcodeContent
                          << "\" from " << mcodeFile
                          << " was not found in " << transmissionFile << std::endl;
            }
        }
    }

    return 0;
}
