// Write a program to check whether the entered word is a keyword or not.

#include <stdio.h>
#include <string.h>

void main(void) {
    int flag = 0, i;
    char str[80];
    char* words[] = {"auto", "break", "case", "int", "float", "char", "if", "void", "sizeof"};
    int num = sizeof(words) / sizeof(words[0]);
    printf("Enter a lexeme: ");
    scanf("%s", str);
    for (i = 0; i < num; i++) {
        if (strcmp(str, words[i]) == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        printf("Keyword");
    }
    else {
        printf("Not Keyword");
    }
}