#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*

You are given a string s. It contains following words: "subtract", "add", "multiply", "divide" followed by one-digit numbers. 
Start with x = 1 and use the operations in the string from left to right on it. At the end, output x.

Examples:
[input] "add1subtract2"
[output] 0
Note: x = 1 initially, adding 1 makes it 2, subtracting 2 makes it 0

*/


int main(int argc, char** argv) {
    char input[512];
    scanf("%s", input);
    int input_len = strlen(input);

    double x = 1; // base

    for (int i = 0; i < input_len; i++) {
        char ic[10];
        int ic_tracker = 0;

        if (input[i] == 'a') { 
            i += 3;

            while (isdigit(input[i])) {
                ic[ic_tracker] = input[i];


                ic_tracker++;
                i++;
            }

            x += atoi(ic);
            i--;
        } else if (input[i] == 's') {
            i += 8;

            while (isdigit(input[i])) {
                ic[ic_tracker] = input[i];

                ic_tracker++;
                i++;
            }

            x -= atoi(ic);
            i--;
        } else if (input[i] == 'm') {
            i += 8;

            while (isdigit(input[i])) {
                ic[ic_tracker] = input[i];

                ic_tracker++;
                i++;
            }

            x *= atoi(ic);
            i--;
        } else if (input[i] == 'd') {
            i += 6;

            while (isdigit(input[i])) {
                ic[ic_tracker] = input[i];

                ic_tracker++;
                i++;
            }

            x /= atoi(ic);
            i--;
        }
    }

    printf("%d", (int)x);
}