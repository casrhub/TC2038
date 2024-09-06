#include "Manacher.h"
#include <iostream>

// Pre processing function to generate the transmission string for example "^#c#a#b#$"
std::string preprocess (const std::string& s) {
    std::string result = "^";
    for (char c : s) {
        result += "#" + std::string(1, c);
    }
    result += "#$";
    return result;
}


// Manacher algorithm 

std::pair<int, int> manacher(const std::string& transmission) {
    std::string T = preprocess(transmission); // apply the preprocess function to our transmission T = Transmission 
    int n = T.length();
    std::vector<int> P(n,0); // Array  for the values of the current longest palindromes found initialized in 0s
    int C = 0, R = 0; // Center and Right Boundary 
    int maxLen = 0 , centerIndex = 0;

    for (int i = 1; i < n; ++i){
        int mirror = 2 * C - i; 

        if ( i < R) {
             P[i] = std::min(R - i, P[mirror]);
        }

        // Try to expand the palindrome in center i 
        while (T[i + (1 + P[i])] == T[i - (1 + P[i])]) {
            P[i]++;
        }

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }

        // Track the longest palindrome
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    int startIndex = (centerIndex - maxLen) / 2;
    int endIndex = startIndex + maxLen - 1;

    return {startIndex + 1, endIndex + 1}; 

}