#include "arv.h"


struct Arv* gerarNo(int op, struct Arv* p1, struct Arv* p2){
    struct Arv *p = (struct Arv *)malloc(sizeof(struct Arv));

    p->op = op;
    p->p1 = p1;
    p->p2 = p2;

    return p;
}

struct Arv* gerarFolha(double valor){
    struct Arv *p = (struct Arv *)malloc(sizeof(struct Arv));
    printf("Valor: %lf\n", valor);
    p->valor = valor;
    p->p1 = NULL;
    p->p2 = NULL;

    return p;
}

char getOperador(enum Operadores op){
    switch(op){
        case ADD:
            return '+';
            break;
        case SUB:
            return '-';
            break;
        case MUL:
            return '*';
            break;
        case DIV:
            return '/';
            break;
        default:
            return '_';
            break;
    }
}

void printarNo(struct Arv *no){
    if (no == NULL)
        return;

    printf("(%c ", getOperador(no->op));
    if (no->p1 != NULL){
        printarNo(no->p1);
    }
    if (no->p2 != NULL){
        printarNo(no->p2);
    }

    if (no->p1 == NULL && no->p2 == NULL){
        printf(" %.3lf", no->valor);
    }


    printf(")");
}