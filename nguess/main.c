#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// #define DEBUG

/*

An integer between 1 and 10^9 is generated and your task is to guess it.
You are given a function that checks your input and gives further information like "Greater" if your number is greater than the generated one, "Smaller" if it is smaller and "Correct" if you guessed it.

The maximum amount of tries is 30, your task is to write a program that always guesses the random number in/under 30 tries.

*/

int pow_l(int n, int p) {
    int t = n;
    for (int i = 1; i < p; i++) {
        n *= t;
    }
    return n;
}

int guess_check(int cn, int n) {
    if (n == cn) {
        return 0;
    } else if (n < cn) {
        return -1;
    } else if(n > cn) {
        return 1;
    }
}

int main(int argc, char** argv) {
    
    int min = 1;
    int max = pow_l(10, 9);

    int cr_guess;
    int tries = 30;

    srand(time(NULL));
    int rand_g = rand() % max + 1;
    printf("%d", rand_g);

    while (--tries + 1) {
        int med = (min + max)/2;

        int res = guess_check(rand_g, med);

        #ifdef DEBUG
            printf("\nMin: %d, Max: %d, Med: %d", min, max, med);
        #endif

        if (!res) {
            printf("\nResult: %d\nCorrect number: %d\nTries used: %d", med, rand_g, 30 - tries);
            break;
        } else if (res == 1) {
            max = med;
        } else if (res == -1) {
            min = med;
        }
    }

}