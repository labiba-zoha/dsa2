#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort by value-to-weight ratio
bool mycomp(pair<int, int> p1, pair<int, int> p2) {
    double r1 = (double)p1.second / p1.first;
    double r2 = (double)p2.second / p2.first;
    return r1 > r2;
}

// Fractional Knapsack Function
double fractionalKnapsack(vector<pair<int, int>> &arr, int w) {
    sort(arr.begin(), arr.end(), mycomp); // Sort items by ratio
    double profit = 0;

    for (int k = 0; k < arr.size(); k++) {
        if (w <= arr[k].first) { // Can only take a fraction of the current item
            double r = (double)w / arr[k].first;
            profit += arr[k].second * r;
            w = 0; // Knapsack full
            break;
        } else { // Take the whole item
            profit += arr[k].second;
            w -= arr[k].first;
        }
    }

    return profit;
}

int main() {
    int w = 20; // Knapsack capacity
    vector<pair<int, int>> arr = {
        {5, 80},
        {10, 150},
        {8, 120},
        {3, 50}
    };

    // Step 1: Deduct one weight from each item and compute initial profit
    double profit = 0.0;
    vector<pair<int, int>> newarr;

    for (auto &item : arr) {
        if (w > 0) {
            profit += (double)item.second / item.first; // Add the profit from 1 unit
            w -= 1; // Deduct 1 unit from capacity
            if (item.first > 1) {
                // Reduce weight and push the remaining portion into newarr
                newarr.push_back({item.first - 1, item.second});
            }
        }
    }

    // Step 2: Use the remaining capacity in a greedy way
    double totalProfit = profit + fractionalKnapsack(newarr, w);

    // Output the total profit
    cout << fixed << setprecision(2) << totalProfit << endl;

    return 0;
}
