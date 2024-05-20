#ifndef ATRIB_H
#define ATRIB_H

#include <stdlib.h>
#include <stdio.h>

#include "arv.h"

struct Atrib {
    struct Arv *ptr;
    double valor;
};

void printarArvore(struct Atrib *);

#endif