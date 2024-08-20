#include <iostream>
#include <vector>
#include <algorithm>


void printChange (const std::vector<int>& denominations, int amount) {
    // vector to store coins used 
    std::vector<int> used_coins(denominations.size(), 0); // vector initialized with the size of the quantity of the denominations and filled with 0s

    // iteration from the largest to the smallest, note: the vector should be already sorted
    for (size_t i = 0; i < denominations.size(); i++){
// we assign the vector the used coins the anount / denomination from the denom array that way we have for example
// amount 140, denomination[ 50, 20, 10 ], then 140 / 50 = 2, so we get how many coins of the current i denomination iteration we are using 
        used_coins[i] = amount / denominations[i]; 

// the amount is updated based on the prevoius divison 

        amount %= denominations[i];
    }

    for (size_t i = 0; i < denominations.size(); i++) { 
        std::cout << denominations[i] << " coin: " << used_coins[i] << std::endl;
    }


}
    
int main() {
    // Inputs: price of the item and amount given by the customer
    int price, amountGiven;
    std::cout << "Enter the price of the item: ";
    std::cin >> price;
    std::cout << "Enter the amount given: ";
    std::cin >> amountGiven;

    // Calculate the change required
    int change = amountGiven - price;
    if (change < 0) {
        std::cout << "Insufficient amount given. No change can be calculated.\n";
        return 1; // Exit with an error code
    }

    std::cout << "Change required: " << change << std::endl;

    // Define the denominations available
    std::vector<int> denominations = {50, 20, 10, 5, 1}; // Include smaller denominations to handle any change
    std::sort(denominations.begin(), denominations.end(), std::greater<int>()); // Ensure the vector is sorted in descending order

    // Calculate and print the coins used for the change
    printChange(denominations, change);

    return 0;
}