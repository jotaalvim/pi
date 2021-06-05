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
    //if (!l) return;
    //while (l->prox) {
    //    printf("%d\n",l->valor);
    //    l = l->prox;
    //}
    while(l) {//!=NULL
        printf("%d\n",l->valor);
        l = l->prox;
    }
}

LInt reverseL (LInt l) {//p4
    if(!l) return l;
    LInt ant = NULL;// anterior
    LInt a = l; // princiap
    while ( a != NULL) {
        LInt x = a->prox;//seguinte
        a->prox = ant;
        ant = a;
        a = x;
    } 
    return ant;
}


void insertOrd (LInt * l, int x) { //p5
    LInt nova;
    nova = (LInt) malloc(sizeof(struct lligada));
    nova->valor = x;
    while( *l != NULL && (*l)->valor <= x) {
        l = &((*l)->prox) ;
    }   
    nova->prox = *l;
    *l = nova;
}


int removeOneOrd (LInt *l, int x) { //p6
    int r = 1;
    LInt aux;
    while(*l != NULL && (*l)->valor != x) 
        l = &((*l)->prox);
    if ((*l)!= NULL) {
        aux = *l;
        (*l) = (*l)->prox;
        free(aux);
        r = 0;
    }
    return r;
}
int removeOneOrd (LInt * lista, int x) {
    LInt ant, atual;
    atual = *lista;
    if (atual == NULL)
        return 1;
    if (atual->valor == x) {
        *lista = NULL;
        return 0;
    }
    while (atual->prox != NULL) {
        ant = atual;
        atual = atual->prox;
        if (atual->valor == x) {
            ant->prox = atual->prox;
            return 0;
        }
    }
    return 1;
}
 

void merge(LInt* r, LInt a, LInt b) {//p7
    if(!a && !b) return;
    if(b == NULL || a != NULL && a->valor < b->valor) {
        (*r) = a;
        merge(&((*r)->prox),a->prox,b);
    }
    else {
        (*r) = b;
        merge(&((*r)->prox),a,b->prox);
    }
}

void splitQS (LInt l, int x, LInt *mx, LInt *Mx) { //p8 


void removeMaiorA (ABin *a) {
    
    if (*a == NULL) return;
    while ((*a)->dir != NULL) {
        a = &((*a)->dir);
    }
    *a = (*a)->esq;
} 


