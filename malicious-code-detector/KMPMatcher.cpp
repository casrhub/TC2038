#include "KMPMatcher.h"
#include <iostream>


std::vector<int> computeKMPTable (const std:: string& pattern) {
    int len = 0; 
    int n = pattern.length();
    std::vector<int> pi(n, 0);
    int i = 1; 
    

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            pi[i] = len;
            i++;

        } else {
            if (len != 0) {
                len = pi[len - 1 ];
            } else {
                pi[i] = 0;
                i++; 
            }
        }

    }

     return pi; 

}



int main() {
    std::string pattern;
    std::cout << "Enter a pattern string: ";
    std::cin >> pattern;

    std::vector<int> pi = computeKMPTable(pattern);

    std::cout << "The KMP table for \"" << pattern << "\" is: ";
    for (int i : pi) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}




