#include <stdio.h>

/*

You are given some sequence of numbers and your task is to continue it with one more number.
The difference to the challenge before is that here, the changes are not constant, but increasing/decreasing by a constant number.
The array will have a minimum of three elements and will always be a valid sequence.

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

    // get differences between pair of sequences
    int first_change_dif = sequence[1] - sequence[0];
    int second_change_dif = sequence[2] - sequence[1];

    // get the change between the differences
    int final_dif = second_change_dif - first_change_dif;

    int resuming_int = sequence[ts_cases - 1] + (sequence[ts_cases - 1] - sequence[ts_cases - 2] + final_dif);

    printf("%d", resuming_int);

    return 0;
}