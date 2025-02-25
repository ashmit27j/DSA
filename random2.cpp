#include <iostream>
using namespace std;
// Structure to store item details
struct Item {
    int weight;
    int profit;
};
// Function to swap two items (for sorting)
void swap(Item &a, Item &b) {
    Item temp = a;
    a = b;
    b = temp;
}
// Function to sort items in descending order based on profit-to-weight ratio
void sortItems(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double ratio1 = (double)items[j].profit / items[j].weight;
            double ratio2 = (double)items[j + 1].profit / items[j + 1].weight;
            if (ratio1 < ratio2) {
                swap(items[j], items[j + 1]);
            }
        }
    }
}
// Function to solve the Fractional Knapsack Problem
double fractionalKnapsack(int capacity, Item items[], int n) {
    // Sort items based on profit-to-weight ratio
    sortItems(items, n);
    double totalProfit = 0.0; // Stores the maximum profit obtained
    int remainingCapacity = capacity; // Remaining weight that can be added to the knapsack
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            // If the entire item can be picked
            totalProfit += items[i].profit;
            remainingCapacity -= items[i].weight;
        } else {
            // If only a fraction of the item can be picked
            totalProfit += (double)items[i].profit * remainingCapacity / items[i].weight;
            break; // Knapsack is full, so we stop
        }
    }
    return totalProfit;
}
int main() {
    int capacity = 60; // Maximum weight the thief can carry
    int n = 4; // Number of items
    // Given items with their weights and profits
    Item items[4] = {
        {40, 280},
        {10, 100},
        {20, 120},
        {24, 120}
    };
    // Calculate the maximum profit
    double maxProfit = fractionalKnapsack(capacity, items, n);
    // Display the result
    cout << "Maximum Profit that can be obtained: rupee" << maxProfit << endl;
    return 0;
}