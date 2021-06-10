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
void insertOrd2 (LInt *l, int x){
    LInt aux = *l;
    LInt nodo = newLInt (x,NULL);
    if (aux == NULL || x < aux->valor) {
        nodo->prox = aux;
        *l = nodo;
        return;
    }
    while (aux->prox != NULL && x >= aux->prox->valor ) {
        aux = aux->prox;
    }
    nodo->prox = aux->prox;
    aux->prox = nodo;
}
LInt newLInt (int v, LInt t){
    LInt nova = (LInt) malloc (sizeof(struct lligada));
    if ( nova != NULL) {
        nova->valor = v;
        nova->prox = t;
    }
    return nova;
}
LInt inseraux (LInt l, int x) {
    if (l == NULL) return newLInt(x,NULL);
    if ( x < l->valor) return newLInt(x,l);
    l->prox = inseraux (l->prox,x);
    return l;
}
void insertOrd3 (LInt *l, int x){
    *l = inseraux (*l,x);
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
 

void merge (LInt *r, LInt l1, LInt l2){ //p7
    LInt aux = *r;
    if (l1 == NULL) aux = l2;
    else
    if (l2 == NULL) aux = l1;
    else
    if (l1->valor < l2->valor) {
        aux = l1;
        merge (&(aux->prox), l1->prox, l2);
    }
    else
    if (l1->valor >= l2->valor) {
        aux = l2;
        merge (&(aux->prox), l1, l2->prox);
    }
    //r = &aux;  muda o valor cá dentro
    *r = aux;
}
void merge2(LInt* r, LInt a, LInt b) {//p7
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

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){//p8
    LInt meno;
    LInt maio;
    if (l == NULL) {
        maio = NULL;
        meno = NULL;
    }
    else
    if (l->valor < x) {
        meno = l;
        splitQS (l->prox , x, &(meno->prox), &(maio));
    }
    else
    if (l->valor >= x) {
        maio = l;
        splitQS (l->prox , x, &(meno), &(maio->prox));
    }
    *Mx = maio;
    *mx = meno;
}

int conta (LInt l) {
    if (l != NULL) return 1 + conta (l->prox);
    else return 0;
}

LInt parteAmeio (LInt *l){//p9
    LInt l1 = *l, l2;
    LInt aux = *l;
    int t1 = conta (aux)/2 , i;
    if (t1 == 0) {
        l1 = NULL;
        l2 = aux;
    }
    else {
        for ( i = 1; i < t1; i++) {
            aux = aux->prox;
        }
        l2 = aux->prox;
        aux->prox = NULL;
        *l = l2; 
    }
    return l1;
}

int removeAll (LInt *l, int x){
    LInt aux = *l;
    LInt final = *l;
    int c = 0;
    while (aux != NULL && aux->valor == x) {
        aux = aux->prox;
        c++;
    }
    final = aux;
    while (aux != NULL && aux->prox != NULL) {
        if (aux->prox->valor == x) {
            c++;
            aux->prox = aux->prox->prox;
        }
        else {
            aux = aux->prox;
        }
    }
    *l = final;
    return c;
}
int removeAll2 (LInt *l, int x){
    LInt final,aux;
    int c = 0;
    //adicionei um no aux no iníncio
    struct lligada ini;
    ini.prox = *l;
    final = aux = &ini;

    while (aux != NULL && aux->prox != NULL) {
        if (aux->prox->valor == x) {
            c++;
            aux->prox = aux->prox->prox;
        }
        else aux = aux->prox;
    }
    *l = final->prox;
    return c;
}

int removeDups (LInt *l){//p11
    LInt aux = *l;
    if (aux->prox == NULL) return 0;
    removeAll(&(aux->prox), aux->valor);
    aux = aux->prox;
    return 1 + removeDups(&(aux));
}

int maior (LInt *l,int x) {
    LInt aux = *l;
    if (aux == NULL) return x;
    x = x > aux->valor ? x : aux->valor;
    return maior (&(aux->prox),x);
    
}
int removeMaiorL (LInt *l){//p12
    LInt aux = *l;
    int c = maior (l,aux->valor );
    while (aux->prox != NULL) {
        if (aux->prox->valor == c) {
            aux->prox = aux->prox->prox;
            break;
        }
        aux = aux->prox; 
    } 
    return c;
}

LInt tira (LInt l) {
    if (l->prox == NULL) {
        free(l);
        return NULL;
    }
    l->prox = tira(l->prox);
    return l;
}
void init (LInt *l){ //p13
    *l = tira(*l);
}

LInt poe (LInt l, int x){
    if (l == NULL) {
        LInt novo = malloc(sizeof(struct lligada));
        novo->valor = x;
        novo->prox = NULL;
        return novo;
    }
    l->prox = poe(l->prox,x);
    return l;
}
void appendL (LInt *l, int x){//p14
    *l = poe(*l,x);
}

void concatL (LInt *a, LInt b){//p15
    LInt aux = *a;
    if (aux == NULL) *a = b;
    else {
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = b;
    }
}

LInt cloneL (LInt l) {//p16
}

int depth (ABin a, int x) {//p34
    if (a == NULL)     return -1;
    if (a->valor == x) return 1;
    
    int e = depth(a->esq,x);
    int d = depth(a->dir,x);
    
    if ( e == -1 && d == -1) return -1; 
    if ( e == -1 || d == -1) return e > d ? e + 1 : d + 1; 
    return e < d ? e + 1 : d + 1; 
}









int auxsoma (ABin a){
    if (a == NULL) return 0;
    return a->valor + auxsoma(a->esq) + auxsoma(a->dir);
}
ABin somasAcA (ABin a) { //p41
    ABin nova = (ABin) malloc(sizeof(struct nodo));
    int c = 0;
    if (a == NULL) return NULL;
    else {
        c += auxsoma(a);
        nova->valor = c;
        nova->esq = somasAcA(a->esq);
        nova->dir = somasAcA(a->dir);
    }
    return nova;
}

void removeMaiorA (ABin *a) {//p48
    
    if (*a == NULL) return;
    while ((*a)->dir != NULL) {
        a = &((*a)->dir);
    }
    *a = (*a)->esq;
} 


