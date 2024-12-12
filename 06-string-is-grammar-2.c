// Write a program to check whether string belongs to corresponding grammar or not.

#include <stdio.h>
#include <string.h>

void main(void) {
    char str[50];
    int count = 0, flag = 1;
    printf("The grammar is: S -> aSb , S -> ab , S -> epsilon");
    printf("Enter the string to be checked: ");
    gets(str);
    if (str[0] == '\0') {
        printf("String accepted (epsilon)");
    }
    else {
        while (str[count] != '\0') {
            if (str[count] == 'a' && str[count + 1] == 'b') {
                count = count + 2;
                continue;
            }
            else {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("String accepted");
        }
        else {
            printf("String not accepted");
        }
    }
}