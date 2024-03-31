// Coin Change Problem: Calculate the minimum number of coins required to make a certain amount.

#include <iostream>
#include <vector>
#include <algorithm> // Include necessary libraries

using namespace std; // Use the standard namespace

// Function to calculate the minimum number of coins required
int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end(), greater<int>()); // Sort the coins in descending order using 'greater' comparator
    /*To sort coin, we need to keep those coin in descending order. So that we can start checking with big coin first*/

    int result = 0; // Initialize the result to store the minimum number of coins
    for (int coin : coins) { // Iterate over each coin
        if (amount == 0) break; // If the amount is 0, no more coins are needed

        int count = amount / coin; // Find the maximum number of this coin that fits into the remaining amount
        /*This line calculates how many times the current coin denomination can fit into the remaining amount. It uses integer division, which means it will only consider whole coins, not fractions.
For example, if amount is 23 and coin is 5, count will be 4 because 5 can fit into 23 four times (ignoring the remainder).*/

        result += count; // Add the count of coins to the result
        /*Here, we add the count of coins we just calculated to the result. The result variable keeps track of the total number of coins used so far.
Using the previous example, if result was initially 0, it will now be 4 after this line executes.*/

        amount -= coin * count; // Subtract the value of the coins from the remaining amount
        /*This line updates the amount by subtracting the total value of the coins we’ve just used. It multiplies the coin’s value (coin) by the number of coins (count) and subtracts this from the amount.
Continuing the example, amount will be updated from 23 to 3 (23 - (5 * 4) = 3).*/
    }

    // If there is any remaining amount, the problem cannot be solved with the given coin denominations
    return amount == 0 ? result : -1;
}

// Main function
int main() {
    cout << "How many types of coins are there? "; // Prompt the user for the number of coin types
    int n; // Variable to store the number of coin types
    cin >> n; // Read the number of coin types

    vector<int> coins(n); // Create a vector to store the coin denominations
    cout << "Enter the coins: "; // Prompt the user to enter the coin denominations
    for (int i = 0; i < n; ++i) { // Loop to read the coin denominations
        cin >> coins[i]; // Read each coin denomination
    }

    cout << "Enter the amount: "; // Prompt the user to enter the amount
    int amount; // Variable to store the amount
    cin >> amount; // Read the amount

    int ans = coinChange(coins, amount); // Call the coinChange function and store the result in 'ans'
    if (ans != -1) {
        cout << "Minimum number of coins required: " << ans << endl; // Output the minimum number of coins required
    } else {
        cout << "No solution exists with the given coin denominations." << endl; // Output if no solution exists
    }
    return 0; // Return 0 to indicate successful completion
}
