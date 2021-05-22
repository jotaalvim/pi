#include <stdlib.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

void libertaLista (Palavras l) {
    if (l) { //l != NULL
        libertaLista( l->prox ) ;
        free(l);
    }
}

int quantasP (Palavras l) {
    int r = 0;
    while (l) { //l != NULL
       r++;
       l = l -> prox;
    }
    return r;
    // if (l != NULL) 
    //  r = 1+ quantasP (l->prox);
}

void listaPal (Palavras l) {
    while (l) { //l != NULL
        printf ("%s -> %d", l->palavra , l-ocorr);
        l = l -> prox;
    }
    // if (l != NULL ) {
    //    printf ("%s -> %d", l->palavra , l-ocorr);
    //    listaPal(l->pox);
    // se troarmos aordem destes comandos imprimos a lista ao contrário
}

char * ultima (Palavras l) {
   // if (l!= NULL) {
   //     while (l->prox) l = l-> prox;
   //     return l-> palarva
   // }
   // return r;
   //     
    char * r;
    if ( l != NULL) r = NULL;
    else
    if ( l->prox == NULL ) r = l->palavras;
    else
        r = ultima (l-> prox);
    return r; 
}

Palavras acrescentaInicio (Palavras l, char *p) {
    //Palavras nova = malloc(sizeof(Palavra)); ERRADO, QUERMOS REQUESITAR ESPAÇO PARA UMA STRUCT CELULA
    Palavras nova = malloc(sizeof(struct celul));
    nova->palavra = p;
    nova->ocorr = 1;
    nova->prox = l;
    return nova;
}

Palavras acrescentaFim (Palavras l, char *p){
    Palavras nova = NULL;
    if (l != NULL) {
        while (l->prox) l = l->prox;
        l->prox = acrescentaInicio(NULL,p);
    }
    else
        r = acrescentaInicio(NULL,p);
    return r;
}

Palavras encontra (Palavras l, char *p) {
    while (l!= NULL && strcmp(l-> palavra, != p)
        l = l->prox;
    return l;
}

Palavras acrescenta (Palavras l, char *p){
    Palavras r = l;
    Palavras igual = encontra(l, p);
    if (igual !=NULL) igual->ocorr++;
    else
        r = acrescentaInicio(l, p);
    return r;
}

Palavras acrescenta (Palavras l, char *p) {
    if (!l) //l == NULL
        while (l && strcmp(l->palavra,p->prox) < 0)
            l = l->prox;
        
    Palavra nova = acrescentaInicio(NULL,p);







