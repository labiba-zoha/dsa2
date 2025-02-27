
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // A large value representing infinity
const int MAX = 100; // Maximum amount size
int cache[MAX + 1];  // Cache to store results
int parent[MAX + 1]; // Parent array to trace coins used

// Recursive function for coin change
int coin_change(int amount, int coins[], int n)
{
    // Base case: no coins needed for amount 0
    if (amount == 0)
        return 0;

    // If already calculated, return the cached result
    if (cache[amount] != -1)
        return cache[amount];

    int result = INF;

    // Try each coin
    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= amount)
        { // Only consider coins <= amount
            int remaining = amount - coins[i];
            int total_coins = coin_change(remaining, coins, n) + 1;

            // Update result if a better solution is found
            if (total_coins < result)
            {
                result = total_coins;
                parent[amount] = coins[i]; // Store the coin used
            }
        }
    }

    // Store the result in the cache
    cache[amount] = result;
    return result;
}

int main()
{
    int n = 3;
    int amount = 10;
    int coins[] = {1, 5 ,5};

    // Initialize cache and parent arrays
    memset(cache, -1, sizeof(cache));
    memset(parent, -1, sizeof(parent));

    int result = coin_change(amount, coins, n);

    // Output the result
    if (result >= INF)
    {
        cout << "Not possible to make the amount with given coins.\n";
    }
    else
    {
        cout << "Minimum coins needed: " << result << endl;

        // Trace back the coins used
        cout << "Coins used: ";
        int curr = amount;
        while (curr > 0)
        {
            cout << parent[curr] << " ";
            curr -= parent[curr];
        }
        cout << endl;
    }


}
