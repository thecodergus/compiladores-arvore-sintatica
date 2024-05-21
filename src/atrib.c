#include "atrib.h"

void printarArvore(struct Atrib *arv){
    if (arv == NULL){
        return;
    }
    printarNo(arv->ptr);
    printf("\n");
}