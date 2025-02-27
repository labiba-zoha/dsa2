#include <stdio.h>

int floorsqure_recursive(int low, int high, int x)
{
    if (low > high) {
        return high;  // Return high when the search is completed
    }

    int mid = (low + high) / 2;
    if (mid * mid <= x) {
        return floorsqure_recursive(mid + 1, high, x);  // Search the right half
    } else {
        return floorsqure_recursive(low, mid - 1, x);  // Search the left half
    }
}

int floorsqure(int x)
{
    return floorsqure_recursive(1, x, x);  // Call the recursive function
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d", floorsqure(x));  // Output the result
}

