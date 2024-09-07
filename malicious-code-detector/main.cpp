#include "KMPMatcher.h"
#include "Manacher.h"
#include "LCS.h"
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

    // Part 1: Loop through each transmission file and mcode file combination
    std::cout << "------------ Part 1: Pattern Matching ------------" << std::endl;
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

    // Part 2: Analyze the mirrored code (longest palindrome) for both transmission files
    std::cout << "------------ Part 2: Longest Palindrome ------------" << std::endl;
    for (const std::string& transmissionFile : transmissionFiles) {
        std::string transmissionContent = readFileContent(transmissionFile);

        if (transmissionContent.empty()) {
            std::cerr << "Transmission file is empty or couldn't be read." << std::endl;
            continue;
        }

        std::pair<int, int> palindromeRange = manacher(transmissionContent);

        std::cout << "Longest mirrored code (palindrome) in " << transmissionFile
                  << " starts at position " << palindromeRange.first
                  << " and ends at position " << palindromeRange.second << std::endl;
    }

    // Part 3: Analyze the longest common substring between transmission1.txt and transmission2.txt
    std::cout << "------------ Part 3: Longest Common Substring ------------" << std::endl;
    std::string transmission1 = readFileContent("transmission1.txt");
    std::string transmission2 = readFileContent("transmission2.txt");

    if (transmission1.empty() || transmission2.empty()) {
        std::cerr << "One or both transmission files are empty or couldn't be read." << std::endl;
        return 1;
    }

    // Find the longest common substring between transmission1 and transmission2
    std::pair<int, int> lcsRange = longest_common_substring(transmission1, transmission2);

    std::cout << "Longest common substring between transmission1.txt and transmission2.txt starts at position "
              << lcsRange.first << " and ends at position " << lcsRange.second << " in transmission1.txt" << std::endl;

    return 0;
}
