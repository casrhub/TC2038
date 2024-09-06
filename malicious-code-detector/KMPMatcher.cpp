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


bool KMPSearch(const std:: string& text, const std:: string& pattern, int& index) {
    int n = text.length();
    int m = pattern.length();

    if ( m == 0 || n == 0){
        return false;
    }


    std::vector<int>pi = computeKMPTable(pattern); 
    int i = 0;
    int j = 0;
    bool found = false;
    index -1; 


    while (i < n) { 
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[ j - 1 ];
        }

        if (text[i] == pattern[j]) {
            j = j + 1; 
         } 

        if (j == m ) { 
            found = true;
            index = i - m + 1;
            j = pi[j - 1];

        }
        i++;
    }

    return found; 


}




