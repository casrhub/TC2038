#include <iostream>
#include <vector>

// Merge algorithm

// Space complexity: O(n) , since we have two temp arrays created of num1 and num2 sizes. 
// Time complexity: O(n)
void merge(std::vector<int>& array, int start, int half, int end) {
    int num1 = half - start + 1;
    int num2 = end - half;
    std::vector<int> L(num1), R(num2);

    // Copying the elements into separate arrays
    // First half
    for (int i = 0; i < num1; i++) {
        L[i] = array[start + i];
    }
    // Second half
    for (int j = 0; j < num2; j++) {
        R[j] = array[half + 1 + j];
    }

    // Variable initialization for the main sorted array
    int i = 0; // Initial index of the first subarray (L)
    int j = 0; // Initial index of the second subarray (R)
    int k = start; // Initial index of the merged subarray

    // Merging
    while (i < num1 && j < num2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // There may be some elements left in L
    while (i < num1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // There may be some elements left in R
    while (j < num2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort algorithm 

// Space complexity: O(n), size of the array
// Time complexity: O(n log n)
void mergeSort(std::vector<int>& array, int start, int end) {
    if (start < end) {
        int half = start + (end - start) / 2;
        mergeSort(array, start, half);
        mergeSort(array, half + 1, end);
        merge(array, start, half, end);
    }
}

int main() {
// Time cpmplexity: O(n log n)
// Space complexity: O(n)
    int count;
    std::cin >> count; // Read the count from standard input

    if (!std::cin) {
        std::cerr << "Failed to read the count of numbers\n";
        return 1;
    }

    std::vector<int> array(count);
    for (int i = 0; i < count; i++) {
        if (std::cin >> array[i]) {
            // Reading the array from input
        } else {
            std::cerr << "Failed to read expected number\n";
            return 1;
        }
    }

    // Merge sort implementation
    mergeSort(array, 0, array.size() - 1);

    // Print sorted array
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
