#ifndef ARV_H
#define ARV_H

#include <stdlib.h>
#include <stdio.h>

enum Operadores{
    ADD,
    SUB,
    MUL,
    DIV
};

struct Arv {
    int op;
    double valor;
    struct Arv *p1, *p2;
};

struct Arv *gerarNo(int, struct Arv*, struct Arv*);
struct Arv *gerarFolha(double);

void printar(struct Arv*);

#endif