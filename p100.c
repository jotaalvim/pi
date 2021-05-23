#include <stdio.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;


int length (LInt l) {//p1
    int c = 1;
    if (!l) return 0;//l == NULL
    
    for(c = 1; l->prox ; c++, l = l->prox);

    //while (l->prox) { //!= NULL
    //    c++;
    //    l = l->prox;
    //}
    return c;
}

void freeL (LInt l) {//p2
    LInt l2;
    if (!l) return;
    while (l->prox) {
        l2 = l;
        l = l->prox;
        free(l2);
    } 
}

void imprimeL (LInt l) {//p3
    if (!l) return;
    while (l->prox) {
        printf("%d\n",l->valor);
        l = l->prox;
    }
}

LInt reverseL (LInt l) {//p4
    if(!l) return NULL;
    while( l->prox) {
        
    }
}

