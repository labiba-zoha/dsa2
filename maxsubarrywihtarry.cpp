#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum of a subarray crossing the midpoint
int MaxCrossingSubarray(int A[], int p, int q, int r, int& crossLeft, int& crossRight) {
    int leftSum = INT_MIN, sum = 0;
    crossLeft = q; // Initialize left boundary
    for (int i = q; i >= p; --i) {
        sum += A[i];
        if (sum > leftSum) {
            leftSum = sum;
            crossLeft = i;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;
    crossRight = q + 1; // Initialize right boundary
    for (int j = q + 1; j <= r; ++j) {
        sum += A[j];
        if (sum > rightSum) {
            rightSum = sum;
            crossRight = j;
        }
    }

    return leftSum + rightSum;
}

// Recursive function to find the maximum subarray sum and track indices
int MaxSubarray(int A[], int p, int r, int& start, int& end) {
    if (p == r) {
        start = end = p;
        return A[p];
    }

    int q = (p + r) / 2;

    // Variables to track indices of the maximum subarray
    int leftStart, leftEnd, rightStart, rightEnd, crossLeft, crossRight;

    int leftMax = MaxSubarray(A, p, q, leftStart, leftEnd);
    int rightMax = MaxSubarray(A, q + 1, r, rightStart, rightEnd);
    int crossMax = MaxCrossingSubarray(A, p, q, r, crossLeft, crossRight);

    if (leftMax >= rightMax && leftMax >= crossMax) {
        start = leftStart;
        end = leftEnd;
        //return leftMax;
    } else if (rightMax >= leftMax && rightMax >= crossMax) {
        start = rightStart;
        end = rightEnd;
        //return rightMax;
    } else {
        start = crossLeft;
        end = crossRight;
        //return crossMax;
    }
    return max({leftMax,rightMax,crossMax});
}

int main() {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(A) / sizeof(A[0]);

    int start = 0, end = 0; // Variables to store the start and end indices of the maximum subarray
    int maxSum = MaxSubarray(A, 0, n - 1, start, end);

    // Print the result
    cout << "Maximum Subarray Sum: " << maxSum << endl;
    cout << "Subarray: ";
    for (int i = start; i <= end; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

