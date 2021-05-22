#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void initStack (Stack *s){
    *s = NULL;
}

int SisEmpty (Stack s){
    return s == NULL;
}

int push (Stack *s, int x){
    int r = 0;
    Stack nova = (Stack) malloc(sizeof(struct slist));
    if (nova != NULL) {
        nova->valor = x;
        nova->prox = *s;
        *s = nova;
    }
    else r = 1;
    return r;
}

int pop (Stack *s, int *x){
    int r = 0;
    Stack aux;
    if (!SisEmpty(*s)) {
        *x = (*s)->valor;
        aux = *s;
        *s -> (*s)->prox;
        free(aux);
    }
    else r = 1;
    return r;
}

int top (Stack s, int *x){
    
}
