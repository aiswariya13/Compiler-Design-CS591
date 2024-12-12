%{
%}
identifer[a-z A-Z][a-z Z-Z 0-9]*
number[0-9]*

%%

int { printf("\n\t%s is a keyword", yytext); }
float { printf("\n\t%s is a keyword", yytext); }
case { printf("\n\t%s is a keyword", yytext); }
char { printf("\n\t%s is a keyword", yytext); }
const { printf("\n\t%s is a keyword", yytext); }
continue { printf("\n\t%s is a keyword", yytext); }
default { printf("\n\t%s is a keyword", yytext); }
{identifer} { printf("\n\t%s is an identifer", yytext); }
{number} { printf("\n\t%s is a number", yytext); }

"=" { printf("\n\t%s is an ASSIGNMENT OPERATOR", yytext); }
";" { printf("\n\t%s is a DELIMETER", yytext); }

%%

void main(int argc, char** argv) {
    if (argc > 1) {
        FILE *fp;
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("Could Not Open %s\n", argv[1]);
            exit(0);
        }
        yyin = fp;
    }
    yylex();
}

int yywrap() {
    return 0;
}