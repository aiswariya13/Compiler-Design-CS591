// Write a program to check whether the entered part is an integer constant or not.

#include <stdio.h>
#include <ctype.h>

void main(void) {
    int flag = 1, i = 0;
    char str[80];
    printf("Enter a lexeme: ");
    scanf("%s", str);
    while (str[i] != '\0') {
        if (isdigit(str[i])) {
            i++;
        }
        else {
            flag = 0;
            break;
        }
    }
    if (flag == 1) {
        printf("Integer Constant");
    }
    else {
        printf("Not an Integer Constant");
    }
}