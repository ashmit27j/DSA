#include <bits/stdc++.h>
using namespace std;

// Function to calculate merge cost for a given sequence
int calculateMergeCost(vector<int> nums) {
    int totalCost = 0;

    // Sort in ascending order initially
    stable_sort(nums.begin(), nums.end());

    // Display initial array
    cout << "Initial sorted array: ";
    for (auto j : nums) cout << j << " ";
    cout << endl;

    // Perform merging
    while (nums.size() > 1) {
        int minCost = INT_MAX;
        pair<int, int> mergePair;

        // Find the best pair to merge (minimize cost)
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int mergeCost = nums[i] + nums[j];
                if (mergeCost < minCost) {
                    minCost = mergeCost;
                    mergePair = {i, j};
                }
            }
        }

        // Merge the chosen pair
        totalCost += minCost;
        int sum = nums[mergePair.first] + nums[mergePair.second];
        nums.erase(nums.begin() + mergePair.second);
        nums.erase(nums.begin() + mergePair.first);
        nums.push_back(sum);

        // Sort again after merging
        stable_sort(nums.begin(), nums.end());

        // Print current state of the array
        for (auto j : nums) cout << j << " ";
        cout << endl;
    }

    return totalCost;
}

int main() {
    vector<int> nums;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Read the input elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    int totalCost = calculateMergeCost(nums);
    cout << "Total Cost: " << totalCost << endl;

    return 0;
}