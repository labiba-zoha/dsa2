#include <stdio.h>
#include <math.h>
#include <string.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Karatsuba algorithm
long long karatsuba(long x, long y) {
    // Base case for recursion
    if (x < 10 || y < 10) {
        return x * y;
    }

    // Calculate the size of the numbers
    int size = max((int)log10(x) + 1, (int)log10(y) + 1);
    int half_size = size / 2;

    // Split the numbers into halves
    long long power = pow(10, half_size);
    long long x_high = x / power;
    long long x_low = x % power;
    long long y_high = y / power;
    long long y_low = y % power;

    // Recursively calculate three products
    long long z0 = karatsuba(x_low, y_low);
    long long z1 = karatsuba((x_low + x_high), (y_low + y_high));
    long long z2 = karatsuba(x_high, y_high);

    // Combine the results
    return (z2 * pow(10, 2 * half_size)) + ((z1 - z2 - z0) * pow(10, half_size)) + z0;
}

int main() {
    long long x, y;
    printf("Enter two numbers to multiply: ");
    scanf("%lld %lld", &x, &y);

    long long result = karatsuba(x, y);
    printf("The product of %lld and %lld is: %lld\n", x, y, result);

    return 0;
}

