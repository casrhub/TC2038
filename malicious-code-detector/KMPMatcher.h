#ifndef KMP_MATCHER_H
#define KMP_MATCHER_H

#include <vector>
#include <string>

// Function to create the partial match table (or "pi" table)
std::vector<int> computeKMPTable(const std::string& pattern);

// KMP search function
bool KMPSearch(const std::string& text, const std::string& pattern, int& index);

#endif
