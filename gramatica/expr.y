%{
#include <stdio.h>
#include <stdlib.h>
#include "arv.h"
#include "atrib.h"
#define YYSTYPE struct Atrib

int yyerror(const char *);
int yylex();

%}
%define parse.error verbose

%token TADD TMUL TSUB TDIV TAPAR TFPAR TNUM TFIM

%%
Linha :Expr TFIM {printf("Resultado:%lf\n", $1);exit(0);}
	; 
Expr: Expr TADD Termo {$$.ptr = gerarNo(ADD, $1.ptr, $3.ptr);}
	| Expr TSUB Termo {$$.ptr = gerarNo(SUB, $1.ptr, $3.ptr);}
	| Termo
	;
Termo: Termo TMUL Fator {$$.ptr = gerarNo(MUL, $1.ptr, $3.ptr);}
	| Termo TDIV Fator {$$.ptr = gerarNo(DIV, $1.ptr, $3.ptr);}
	| Fator
	
Fator: TNUM {$$.ptr = gerarFolha($1.valor);} 
	| TAPAR Expr TFPAR {$$.ptr = $2.ptr;}
	;
%%

int yyerror (const char *str)
{
	fprintf(stderr, "%s\n", str);
	
} 		 

