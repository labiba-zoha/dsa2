#include <stdio.h>
#include <string.h>

// Structure to hold unmatched parentheses count
typedef struct {
    int open_count;  // Unmatched '('
    int close_count; // Unmatched ')'
} ParenthesisCount;

// Function to merge two counts
ParenthesisCount merge(ParenthesisCount left, ParenthesisCount right) {
    // Combine unmatched parentheses
    int matches = left.open_count < right.close_count ? left.open_count : right.close_count;

    ParenthesisCount result;
    result.open_count = left.open_count + right.open_count - matches;
    result.close_count = left.close_count + right.close_count - matches;
    return result;
}

// Recursive function to validate parenthesis using divide and conquer
ParenthesisCount isValidParenthesis(char str[], int start, int end) {
    // Base case: single character
    if (start == end) {
        ParenthesisCount result = {0, 0};
        if (str[start] == '(')
            result.open_count = 1;
        else if (str[start] == ')')
            result.close_count = 1;
        return result;
    }

    // Divide: Find the midpoint
    int mid = (start + end) / 2;

    // Conquer: Recursively process left and right halves
    ParenthesisCount left = isValidParenthesis(str, start, mid);
    ParenthesisCount right = isValidParenthesis(str, mid + 1, end);

    // Combine: Merge results
    return merge(left, right);
}

int main() {
    char str[] = "((())())";
    int n = strlen(str);

    // Get unmatched counts
    ParenthesisCount result = isValidParenthesis(str, 0, n - 1);

    // If both counts are 0, the string is valid
    if (result.open_count == 0 && result.close_count == 0)
        printf("Valid Parenthesis\n");
    else
        printf("Invalid Parenthesis\n");

    return 0;
}

