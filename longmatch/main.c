#include <stdio.h>
#include <string.h>

/*

Given a string stringA and a string stringB, output the longest match of stringB in stringA (at any position).
This means that if stringB isn't directly in stringA, then output the longest subsequence of stringB that is at any position in stringA.

*/

int strlen_l(char* ptr) {
    int lenptr = 0;
    while (*ptr != '\0') { 
        lenptr++; 
        ptr++;
    };
    return lenptr;
}

int main(int argc, char** argv) {

    char input[2048];
    char sub_input[2048];
    char ans_out[2048];

    scanf("%s", input);
    scanf("%s", sub_input);

    for (int i = 0; i < strlen_l(input); i++) {
        for (int j = 0; j < strlen_l(sub_input); j++) {
            
            if (input[i] == sub_input[j]) {
                char temp_buf[2048];
                int mn_it = i;
                int sb_it = j;
                while (input[mn_it] == sub_input[sb_it]) {
                    temp_buf[mn_it - i] = input[mn_it];
                    mn_it++;
                    sb_it++;
                }
                if (strlen_l(temp_buf) > strlen_l(ans_out)) {
                    strcpy(ans_out, temp_buf);
                }
            }
        }
    }

    printf("%s", ans_out);

    return 0;
}