// C++ program to count Minimum number
// of jumps to reach end
#include <iostream>
#include <vector>
using namespace std;

// Returns minimum number of jumps
// to reach arr[n-1] from arr[0]
int minJumps(vector<int>& arr) {
      int n = arr.size();

    // Return -1 if not possible to jump
    if (arr[0] == 0)
        return -1;

    // Stores the maximal reachable index
    int maxReach = 0;

    // stores the number of steps  we can still take
    int currReach = 0;

    // stores the number of jumps needed
      // to reach current reachable index
    int jump = 0;

    // Start traversing array
    for (int i = 0; i < n; i++) {
          maxReach = max(maxReach, i+arr[i]);

          // If we can reach last index by jumping
          // from current position return Jump + 1
          if (maxReach >= n-1) {
              return jump + 1;
        }

          // Increment the Jump as we reached the
          // Current Reachable index
          if (i == currReach) {

              // If Max reach is same as current index
              // then we can not jump further
              if (i == maxReach) {
                  return -1;
              }

              // If Max reach > current index then increment
              // jump and update current reachable index
              else {
                jump++;
                currReach = maxReach;
            }
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

    cout << minJumps(arr);
    return 0;
}
