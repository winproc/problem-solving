#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
You are given a string s and an integer i. Apply the Ceasar Cipher according to the integer i.
Don't apply the Ceasar Cipher to special characters like spaces.
*/

unsigned char recursive_caesar_check(unsigned char result) {
    if (result > 'z') {
        result = 'a' + (result - 'z' - 1);
        
        recursive_caesar_check(result);
    } else {
        return result;
    }
}

int main(void) {
    unsigned char input[2048];
    int shift_i;

    fgets(input, 2048, stdin);
    scanf("%d", &shift_i);

    for (int i = 0; i < strlen(input); i++) {
        if (!isalpha(input[i])) {
            printf(" ");
            continue;
        } else {
            unsigned char c_sh = tolower(input[i]);
            unsigned char result = c_sh + shift_i;
            result = recursive_caesar_check(result);

            printf("%c", result);
        }

    }
}