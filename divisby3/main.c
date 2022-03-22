#include <stdio.h>
#include <string.h>

/*
Given a positive integer n (that contains no zeros at all) of length k. Your task is to be able to delete from 0 to k−1 digits 
in the number n so that you get a positive integer divisible by 3. Note that after deleting the digits, the relative positions 
of the letters remain the same.

- Print out the minimum amount of digits that need to be removed. If not possible then print -1.
- Optional: Print out the new number.
*/

int main(int argc, char** argv) {
    char inp_long[21];
    short answer = 0;
    char ret_v[21];

    scanf("%s", &inp_long);
    size_t inp_len = strlen(inp_long);

    // get sum of all digits
    int sum = 0;
    for (int i = 0; i < inp_len; i++) {
        sum += (inp_long[i] - '0');
    }

    // return if sum is already divisible by 3
    if (sum % 3 == 0) {
        answer = -1;
    }

    for (int i = 0; i < strlen(inp_long); i++) {
        if ((inp_long[i] - '0') % 3 == sum % 3) {
            answer = 1;
            break;
        }
    }


    if (sum == 2 || sum == 7) {
        answer = -1;
    }

    if (answer == 0) {
        answer = 2;
    }

    printf("%d", answer);
}