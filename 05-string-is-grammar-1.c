// Write a program to check whether a string belongs to grammar or not.

#include <stdio.h>
#include <string.h>

void main(void) {
    char str[50];
    int flag = 0, count = 0;
    printf("The grammar is: S -> aS , S -> Sb , S -> ab");
    printf("Enter string to be checked: ");
    gets(str);
    if (str[0] == 'a') {
        flag = 0;
        for (count = 1; str[count - 1] != '\0'; count++) {
            if (str[count] == 'b') {
                flag = 1;
                continue;
            }
            else if ((flag == 1) && (str[count] == 'a')) {
                printf("String does not belong to specified grammar");
                break;
            }
            else if (str[count] == 'a') {
                continue;
            }
            else if ((flag == 1) && (str[count] == '\0')) {
                printf("String Accepted");
                break;
            }
            else {
                printf("String not accepted");
            }
        }
    }
}