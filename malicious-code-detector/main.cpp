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

            // Use KMPSearch to check if the mcode is found in the transmission file
            bool result = KMPSearch(transmissionContent, mcodeContent);

            // Print the result as true or false
            if (result) {
                std::cout << "true: the file " << transmissionFile 
                          << " contains the code in " << mcodeFile << std::endl;
            } else {
                std::cout << "false: the file " << transmissionFile 
                          << " does not contain the code in " << mcodeFile << std::endl;
            }
        }
    }

    return 0;
}
