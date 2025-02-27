#include <bits/stdc++.h>
using namespace std;

int knapsack(int capacity, int val[], int wt[], int item) {
    int dp[capacity + 1];
    memset(dp, 0, sizeof(dp)); // Initialize the dp array with 0

    for (int i = 0; i < item; i++) {
        for (int w = capacity; w >= wt[i]; w--) { // Traverse in reverse
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }

    return dp[capacity]; // The maximum value we can achieve with the given capacity
}

int main() {
    int value[] = {1, 2, 3};
    int weight[] = {4, 5, 1};
    int capacity = 4;

    cout << "Maximum value in knapsack: " << knapsack(capacity, value, weight, 3) << endl;
    return 0;
}
