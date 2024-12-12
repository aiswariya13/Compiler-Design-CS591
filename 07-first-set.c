#include <stdio.h>
#include <ctype.h>

int nop;
char prod[10][10];

void FIRST(char res[],char c) {
    int i,j,k;
    char subres[5];
    int eps;
    subres[0] = '\0';
    res[0] = '\0';
    if (!(isupper(c))) {
        result(res,c);
        return;
    }
    for(i=0; i<nop; i++) {
        if (prod[i][0] == c) {
            if(prod[i][2] == '$') {
                result(res,'$');
            }
            else {
                j = 2;
                while(prod[i][j] != '\0') {
                    eps = 0;
                    FIRST(subres,prod[i][j]);
                    for(k=0; subres[k] != '\0'; k++) {
                        result(res, subres[k]);
                    }
                    for(k=0; subres[k] != '\0'; k++) {
                        if (subres[k] == '$') {
                            eps = 1;
                            break;
                        }
                    }
                    if (!eps) {
                        break;
                    }
                    j++;
                }
            }
        }
    }
    return;
}

void result(char res[],char val) {
    int k;
    for (k=0; res[k]!= '\0'; k++) {
        if (res[k] == val) {
            return;
        }     
    }
    res[k] = val;
    res[k+1] = '\0';
}

void main() {
    int i;
    char choice;
    char c;
    char res1[20];
    printf("How many number of productions: ");
    scanf("%d", &nop);
    printf("Enter production string like E = E + T\n");
    for (i = 0; i < nop; i++) {
        printf("Enter production number %d: ", i + 1);
        scanf("%s", prod[i]);
    }
    do {
        printf("\nFind the First of: ");
        scanf(" %c", &c);
        FIRST(res1, c);
        printf("\nFIRST(%c)={", c);
        for(i=0; res1[i]!='\0'; i++) {
            printf("}\n");
        }
        printf("press y to continue:");
        scanf("%c",&choice);
    }
    while(choice == 'y' || choice == 'Y');
}