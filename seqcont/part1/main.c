#include <stdio.h>

/*

You are given some sequence of numbers and your task is to continue it with one more number. 
All changes from a number to the next are constant/the same.

*/

int main(int argc, char** argv) {

    // number of integers for sequence
    int ts_cases;
    scanf("%d", &ts_cases);

    int sequence[1024];

    // take input for sequence
    for (int i = 0; i < ts_cases; i++) {
        scanf("%d", &sequence[i]);
    }

    // get next sequence int by adding the difference between sequences to the last int
    int resuming_int = sequence[ts_cases-1] + sequence[1] - sequence[0];

    printf("%d", resuming_int);

    return 0;
}