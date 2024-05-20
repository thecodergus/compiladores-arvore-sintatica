#include <stdio.h>
#include "expr.tab.h"

extern FILE *yyin;

int main(){
    yyin = stdin;
    printf("Digite uma expressao: ");
    yyparse();

    return 0;
}