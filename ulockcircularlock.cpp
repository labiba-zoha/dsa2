#include <bits/stdc++.h>
using namespace std;

// function for min rotation without using abs
int minRotation(int input, int unlock_code)
{
    int rotation = 0;
    int input_digit, code_digit;

    // iterate till input and unlock code become 0
    while (input!=0 || unlock_code!=0) {

        // input and unlock last digit as reminder
        input_digit = input % 10;
        code_digit = unlock_code % 10;

        // calculate forward rotation (clockwise) and backward rotation (counterclockwise)
        int forward_rotation = (code_digit - input_digit + 10) % 10;
        int backward_rotation = (input_digit - code_digit + 10) % 10;

        // add the minimum of forward and backward rotations
        rotation += min(forward_rotation, backward_rotation);

        // update code and input
        input /= 10;
        unlock_code /= 10;
    }

    return rotation;
}

// driver code
int main()
{
    int input = 28756;
    int unlock_code = 98234;
    cout << "Minimum Rotation = "
        << minRotation(input, unlock_code);
    return 0;
}
