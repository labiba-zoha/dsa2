#include <stdio.h>

int searchInRotatedArray(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1; // Element not found
    }

    int mid = left + (right - left) / 2;

    // Check if the middle element is the target
    if (arr[mid] == target) {
        return mid;
    }

    // Check if the left half is sorted
    if (arr[left] <= arr[mid]) {
        // If the target is within the sorted left half
        if (target >= arr[left] && target < arr[mid]) {
            return searchInRotatedArray(arr, left, mid - 1, target);
        } else { // Otherwise, search the right half
            return searchInRotatedArray(arr, mid + 1, right, target);
        }
    }

    // Otherwise, the right half must be sorted
    if (target > arr[mid] && target <= arr[right]) {
        return searchInRotatedArray(arr, mid + 1, right, target);
    } else { // Otherwise, search the left half
        return searchInRotatedArray(arr, left, mid - 1, target);
    }
}

int main() {
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = searchInRotatedArray(arr, 0, n - 1, target);
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}

