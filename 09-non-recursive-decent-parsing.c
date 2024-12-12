// Implement non recursive decent parsing

#include <stdio.h>
#include <ctype.h>

char ch;

#define id 0
#define CONST 1
#define mulop 2
#define addop 3
#define of 4
#define op 5
#define crr 6
#define col 7
#define size 50

int token;
char lexbuff[size];
int lookahead = 0;

int main() {
    printf("Enter the string");
    gets(lexbuff);
    parser();
}

parser() {
    if (E()) {
        printf("Valid String");
    }
    else {
        printf("Invalid String");
    }
    return 0;
}

E() {
    if (T()) {
        if (EPrime()) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

EPrime() {
    token = lexer();
    if (token == addop) {
        lookahead++;
        if (F()) {
            if (TPrime()) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
    else {
        return 1;
    }
}

F() {
    token = lexer();
    if (token == id) {
        return 1;
    }
    else {
        if (token == 4) {
            if (E()) {
                if (token == 5) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
}

lexer() {
    if (lexbuff[lookahead] != '\n') {
        if (lexbuff[lookahead] == '\t') {
            lookahead++;
        }
        if (isalpha(lexbuff[lookahead])) {
            while (isalnum(lexbuff[lookahead])) {
                lookahead++;
            }
            return (id);
        }
        else {
            if (isdigit(lexbuff[lookahead])) {
                while (isdigit(lexbuff[lookahead])) {
                    lookahead++;
                }
                return CONST;
            }
            else {
                if (lexbuff[lookahead] == '+') {
                    return (addop);
                }
                else {
                    if (lexbuff[lookahead] == '*') {
                        return (mulop);
                    }
                    else {
                        if (lexbuff[lookahead] == '(') {
                            lookahead++;
                            return (op);
                        }
                        else {
                            if (lexbuff[lookahead] == ')') {
                                if (lexbuff[lookahead] == ')') {
                                    return op;
                                }
                                else {
                                    return err;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}