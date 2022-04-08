#include <stdio.h>

/*

You are given strings a, b and c.
Either b or c were created with following procedure:
a s letters got mixed and some random letters were added.

Output "b" if b was created with that procedure or "c" if c was created with that procedure.
If both b and c couldn't have been created with that procedure, then output "None".
If both could've been created with that procedure, pick the one which has less random letters added.

*/

unsigned int strln(char* str) {
    int n = 0;
    while (*str != '\0') {
        n++;
        str++;
    }
    return n;
}

int main() {
    
    char input_a[2048];
    char input_b[2048];
    char input_c[2048];

    scanf("%s", input_a);
    scanf("%s", input_b);
    scanf("%s", input_c);

    int a_len = strln(input_a);
    int b_len = strln(input_b);
    int c_len = strln(input_c);

    short b_char_ans = 1;
    short c_char_ans = 1;

    for (int i = 0; i < a_len; i++) {
        int lw_success = 0;
        for (int j = 0; j < b_len; j++) {
            if (input_b[j] == input_a[i]) {
                lw_success = 1;
                break;
            }
        } 

        if (!lw_success) {
            b_char_ans = 0;
        }

        lw_success = 0;
        for (int j = 0; j < c_len; j++) {
            if (input_c[j] == input_a[i]) {
                lw_success = 1;
                break;
            }
        } 
        if (!lw_success) {
            c_char_ans = 0;
        }
    }

    if ( !b_char_ans && !c_char_ans ) {
        printf("None\n");
    } else if ( b_char_ans || c_char_ans ) {
        if ( b_char_ans && c_char_ans ) {
            if (b_len < c_len) {
                printf("B\n");
            } else {
                printf("C\n");
            }
        } else if (b_char_ans) {
            printf("B\n");
        } else if (c_char_ans) {
            printf("C\n");
        }
    }
    return 0;
}