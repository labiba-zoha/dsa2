#include <iostream>
#include <algorithm>
using namespace std;

// Recursive binary search function
int binary(int a[], int low, int high, int key) {
    if (low > high)
        return -1; // Key not found
    int mid = (low + high) / 2;
    if (a[mid] == key)
        return mid; // Key found
    else if (a[mid] > key)
        return binary(a, low, mid - 1, key); // Search in the left half
    else
        return binary(a, mid + 1, high, key); // Search in the right half
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int a[100]; // Static array with a large enough size
    cout << "Enter the elements (sorted in ascending order): ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int key;
    cout << "Enter the key to search: ";
    cin >> key;
    sort(a,a+n);

    int flag = binary(a, 0, n - 1, key); // Call the binary search function
    if (flag == -1) {
        cout << "Key not found" << endl;
    } else {
        cout << "Key found at index " << flag << endl;
    }

    return 0;
}
