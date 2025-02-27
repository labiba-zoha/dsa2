#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a string is a palindrome
bool isPalindrome(char str[], int left, int right) {
    if (left >= right) {
        return true;
    } else {
        if (str[left] == str[right]) {
            return isPalindrome(str, left + 1, right - 1);
        } else {
            return false;
        }
    }
}

int main() {
    char str[] = "madam"; // Input string
    int length = strlen(str);

    bool result = isPalindrome(str, 0, length - 1);
    if (result == true) {
        printf("Palindrome\n");
    } else {
        printf("Not a Palindrome\n");
    }

    return 0;
}

