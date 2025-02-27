/*Write a recursive program to find the maximum of a 2d array.Base Case (i == rows):

This happens when we've checked all rows. Return the max value since the entire array has been traversed.
Row Transition (j == cols):

This occurs when all columns of a row are processed. Move to the next row (i + 1) and reset the column index (j = 0).
Element Comparison:

Check if the current element (arr[i][j]) is larger than the current maximum (max). If yes, update max.
Recursive Call:

Continue to the next element in the current row (j + 1) or move to the next row if necessary.We aim to find the maximum element in a 2D array using a recursive approach instead of iterative loops.

Key Concepts:
Breaking Down the Problem:

A 2D array is traversed by iterating through its rows and columns.
At each element, compare it with the current maximum value.
Recursion ensures every element in the array is checked.
Recursive Traversal:

Start from the first row (i = 0) and first column (j = 0).
Move column by column in the same row.
Once all columns in a row are checked, move to the next row.
Base Case:

Stop the recursion when all rows are processed (i == rows).
Recursive Case:

Update the current maximum if the element being checked is larger than the existing maximum.
Move to the next column in the same row. If the end of the row is reached (j == cols), move to the first column of the next row.*/

#include <stdio.h>
#include <limits.h>

// Recursive function to find the maximum in a 2D array
int findMax(int arr[100][100], int rows, int cols, int i, int j, int max) {
    // Base case: If we have processed all rows, return the maximum value
    if (i == rows) {
        return max;
    }

    // Check if the current element is greater than the current max
    if (arr[i][j] > max) {
        max = arr[i][j]; // Update the max value
    }

    // Move to the next column
    if (j + 1 < cols) {
        return findMax(arr, rows, cols, i, j + 1, max); // Continue in the same row
    } else {
        // If the end of the row is reached, move to the next row and start from column 0
        return findMax(arr, rows, cols, i + 1, 0, max);
    }
}
void revprint2DArray(int arr[100][100], int rows, int cols, int i, int j) {
    // Base case: If all rows are processed, stop recursion
    if (i == rows) {
        return;
    }

    // Print the current element


    // Move to the next column
    if (j + 1 < cols) {
        revprint2DArray(arr, rows, cols, i, j + 1); // Continue in the same row
    } else {
        // If the end of the row is reached, move to the next row
         // Move to the next line for a new row
        revprint2DArray(arr, rows, cols, i + 1, 0);
        printf("\n"); // Start from the first column of the next row
    }
     printf("%d ", arr[i][j]);

}
void print2DArray(int arr[100][100], int rows, int cols, int i, int j) {
    // Base case: If all rows are processed, stop recursion
    if (i == rows) {
        return;
    }

    // Print the current element
    printf("%d ", arr[i][j]);

    // Move to the next column
    if (j + 1 < cols) {
        print2DArray(arr, rows, cols, i, j + 1); // Continue in the same row
    } else {
        // If the end of the row is reached, move to the next row
        printf("\n"); // Move to the next line for a new row
        print2DArray(arr, rows, cols, i + 1, 0); // Start from the first column of the next row
    }
}




int main() {
    int rows, cols;

    // Input the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int arr[100][100];

    // Input the elements of the 2D array
    printf("Enter the elements of the 2D array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    revprint2DArray(arr,rows,cols,0,0);

    // Call the recursive function to find the maximum element
    int max = findMax(arr, rows, cols, 0, 0, INT_MIN);

    // Output the maximum element
    printf("The maximum element in the 2D array is: %d\n", max);

    return 0;
}







