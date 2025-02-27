#include <bits/stdc++.h>
//#include<bits/stdc++.h>
using namespace std;

int MaxCrossingSubarray(int A[], int p, int q, int r) {
    int leftSum = INT_MIN, sum = 0;
    for (int i = q; i >= p; --i) {
        sum += A[i];
        if (sum > leftSum) leftSum = sum;
    }

    int rightSum = INT_MIN;
    sum = 0;
    for (int j = q + 1; j <= r; ++j) {
        sum += A[j];
        if (sum > rightSum) rightSum = sum;
    }

    return leftSum + rightSum;
}

int MaxSubarray(int A[], int p, int r) {
    if (p == r) return A[p];
    int q = (p + r) / 2;
    int leftMax = MaxSubarray(A, p, q);
    int rightMax = MaxSubarray(A, q + 1, r);
    int crossMax = MaxCrossingSubarray(A, p, q, r);
    return max({leftMax, rightMax, crossMax});
}

int main() {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(A) / sizeof(A[0]);
    cout << MaxSubarray(A, 0, n - 1) << endl;
    return 0;
}
