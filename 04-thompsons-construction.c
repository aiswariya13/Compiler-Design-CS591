// Write a program to convert a regular expression to NFA using Thompson's Construction.

#include <stdio.h>
#include <string.h>

void main(void) {
    char reg[20];
    int q[20][3] = {0}, i = 0, j = 1, len, a, b;
    printf("Enter regular expression: ");
    scanf("%s", reg);
    len = strlen(reg);
    while (i < len) {
        if (reg[i] == 'a' && reg[i + 1] != '|' && reg[i + 1] != '*') {
            q[j][0] = j + 1;
            j++;
        }
        if (reg[i] == 'b' && reg[i + 1] != '|' && reg[i + 1] != '*') {
            q[j][1] = j + 1;
            j++;
        }
        if (reg[i] == 'e' && reg[i + 1] != '|' && reg[i + 1] != '*') {
            q[j][2] = j + 1;
            j++;
        }
        if (reg[i] == 'a' && reg[i + 1] == '|' && reg[i + 2] != 'b') {
            q[j][2] = ((j + 1) * 10) + (j + 3); j++;
            q[j][0] = j + 1; j++;
            q[j][2] = j + 3; j++;
            q[j][1] = j + 1; j++;
            q[j][2] = j + 1; j++;
            i = i + 2;
        }
        if (reg[i] == 'b' && reg[i + 1] == '|' && reg[i + 2] != 'a') {
            q[j][2] = ((j + 1) * 10) + (j + 3); j++;
            q[j][1] = j + 1; j++;
            q[j][2] = j + 3; j++;
            q[j][0] = j + 1; j++;
            q[j][2] = j + 1; j++;
            i = i + 2;
        }
        if (reg[i] == 'a' && reg[i + 1] == '*') {
            q[j][2] = ((j + 1) * 10) + (j + 3);
            j++;
            q[j][0] = j + 1;
            j++;
            q[j][2] = ((j + 1) * 10) + (j - 1);
            j++;
        }
        if (reg[i] == 'b' && reg[i + 1] == '*') {
            q[j][2] = ((j + 1) * 10) + (j + 3);
            j++;
            q[j][1] = j + 1;
            j++;
            q[j][2] = ((j + 1) * 10) + (j - 1);
            j++;
        }
        if (reg[i] == '|' && reg[i + 1] == '*') {
            q[0][2] = ((j + 1) * 10) + 1;
            q[j][2] = ((j + 1) * 10) + 1;
            j++;
        }
        i++;
    }
    printf("------Transition Table------\n");
    printf("Current State     Next State\n");
    for (i = 0; i <= j; i++) {
        if (q[i][0] != 0) {
            printf("Q[%d] | a | Q[%d]", i, q[i][0]);
        }
        if (q[i][1] != 0) {
            printf("Q[%d] | b | Q[%d]", i, q[i][1]);
        }
        if (q[i][2] != 0) {
            if (q[i][2] < 0) {
                printf("Q[%d] | e | Q[%d]", i, q[i][2]);
            }
            else {
                printf("Q[%d] | e | Q[%d] , Q[%d]", i, q[i][2] / 10, q[i][2] % 10);
            }
        }
    }
}