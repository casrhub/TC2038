#ifndef MANACHER_H
#define MANACHER_H

#include <vector>
#include <string>
#include <utility>  // For std::pair

// Function to receive a transmission and return a pair of indexes
std::pair<int, int> manacher(const std::string& transmission);

#endif
