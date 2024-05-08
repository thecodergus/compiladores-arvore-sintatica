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
    p->valor = valor;
    p->p1 = NULL;
    p->p2 = NULL;

    return p;
}