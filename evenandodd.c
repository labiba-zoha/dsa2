/*arr[low] % 2 == 0:

This expression checks if the element at index low is even.
The modulus operation (% 2) returns the remainder of the division of the number by 2.
If the remainder is 0, the number is even. Therefore, arr[low] % 2 == 0 will evaluate to 1 (true) if the number is even and 0 (false) if it is odd.
arr[high] % 2 == 0:

Similarly, this checks if the element at index high is even.
Sum of Booleans:

The key here is that the + operator adds the results of the two boolean expressions.
Since arr[low] % 2 == 0 and arr[high] % 2 == 0 are either 1 (true) or 0 (false), adding them gives the total count of even numbers between the two elements.
If both arr[low] and arr[high] are even, even_count will be 1 + 1 = 2.
If one of them is even, even_count will be 1 + 0 = 1.
If neither is even (i.e., both are odd), even_count will be 0 + 0 = 0.*/
#include <stdio.h>

// Define a structure to store even and odd counts
struct Evenoddcount {
    int even_count;
    int odd_count;
};

typedef struct Evenoddcount Evenoddcount; // Alias the structure with the same name

// Recursive function to count even and odd numbers
Evenoddcount find(int arr[], int low, int high) {
    // Base case: when low == high, it's a single element
    if (low == high) {
        if (arr[low] % 2 == 0) {
            return (Evenoddcount){1, 0}; // Even count is 1, odd count is 0
        } else {
            return (Evenoddcount){0, 1}; // Even count is 0, odd count is 1
        }
    }
    // Case when there are two elements
    else if (low + 1 == high) {
        int even_count = (arr[low] % 2 == 0) + (arr[high] % 2 == 0);
        int odd_count = (arr[low] % 2 != 0) + (arr[high] % 2 != 0);
        return (Evenoddcount){even_count, odd_count};
    }
    // Recursive case: divide the array into two halves
    else {
        int mid = (low + high) / 2;
        Evenoddcount left = find(arr, low, mid);
        Evenoddcount right = find(arr, mid + 1, high);

        // Combine the counts from the left and right subarrays
        Evenoddcount result;
        result.even_count = left.even_count + right.even_count;
        result.odd_count = left.odd_count + right.odd_count;

        return result;
    }
}

int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the even and odd count in the array
    Evenoddcount result = find(arr, 0, n - 1);

    // Output the results
    printf("Even count: %d\n", result.even_count);
    printf("Odd count: %d\n", result.odd_count);

    return 0;
}
