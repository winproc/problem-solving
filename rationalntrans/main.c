#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

You are given a rational number and your task is to convert it into a fraction in the simplest possible form, 
that is, it also has to be an inductive fraction.

*/

typedef struct {
    char Numerator[20];
    char Denominator[20];
} Fraction;

Fraction get_fraction(char* inp);

Fraction get_fraction(char* inp) {
    Fraction fract;
    fract.Denominator[0] = '1';
    
    int ig_ind = 0;
    
    for (int i = 0; i < strlen(inp); i++) {
        if (inp[i] == '.') {
            ig_ind = 1;
            continue;
        }
        fract.Numerator[i - ig_ind] = inp[i];
        fract.Denominator[i + 1] = '0';
    }

    return fract;
}

int get_hcf(Fraction fract) {
    int deno = atoi(fract.Denominator);
    int num = atoi(fract.Numerator);

    int hcf_target = deno > num ? num : deno; // find the smallest number between denom and num
    int compar_i = hcf_target == num ? deno : num;

    for (int i = hcf_target; i > 1; i--) {
        if (compar_i % i == 0) {
            return i;
        }
    }

    return 1;
}

int main(int argc, char** argv) {

    char input[20];
    scanf("%s", &input);

    Fraction fract = get_fraction(input);
    int div = get_hcf(fract);

    int n_result = atoi(fract.Numerator) / div;
    int d_result = atoi(fract.Denominator) / div;

    printf("\n%d/%d", n_result, d_result);

    return 0;
}