#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct lista {
    int ne;
    int v[2000];
} *lista;

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

void swap (int v[], int i , int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int bubble (int v[], int n) {
    int i;
    int r = 0;
    for ( i = 0; i < n-1; i++){
        if (v[i] > v[i+1]) {
            swap(v, i, i+1);
            r = 1; 
        }
    }
    return r; //retorna 0 se estiver ordenado
}
void bubbleSort ( int v[], int n) {
    int ord = 1;
    while (ord) {
        ord = bubble (v , n);
    }
}   


int pmenor ( int v[], int i, int n) {
    if ( n == i) return i;
    int p = pmenor (v, i+1, n);
    return v[i] < v[p] ? i : p; 
}


int sumhtpo (int n) {
    int r = -1;
    lista m;
    m = malloc (sizeof(struct lista));
    //podia ter feito só struct lista m;
    m->ne = 0;
    //m->v = {0};//tudo a 0
    while (n != 1) {
        m->ne++;
        m->v[m->ne] = n;
        if (n%2 == 0) n = n/2; else n = 1+(3*n);
    }
    //for (int i = 0 ; i < m->ne ; i++) printf("%d ",m->v[i]);
    bubbleSort(m->v, m->ne);
    //for (int i = 0 ; i < m->ne ; i++) printf("%d ",m->v[i]);
    if (m->ne >= 100) return m->v[ 99 ];
    return r;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//   2 

int pmaior ( int v[], int i, int n) {
    if ( n == i) return i;
    int p = pmenor (v, i+1, n);
    return v[i] > v[p] ? i : p; 
}

int moda(int v[], int n, int *m) {
    int freq[n] = {0}; 
    int valores[n] = {0};  
    int iv = 0;

    bubbleSort (v,n);

    for ( int i = 1; i < n ;i++) {
        if ( v[i] == v[i-1] ) {
            freq[iv]++;
        }
        else {
            valores[iv] = v[i-1];
            freq[iv]++;
            iv++;
        }
    }
    int ff = pmaior (freq,iv);
    int aux = freq[ff];
    freq [ff] = 0;
    int ff2 = pmaior (freq,iv);
    if (aux == freq[ff2]) {
        *m = valores[ff];
        return 0;
    }
    else {
        *m = valores[ff];
        return freq[ff];
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//   3

int procura (LInt *l, int x) {
    LInt aux = *l;
    int r = 0;
    if (aux == NULL) return 0;
    
    struct lligada ini;
    ini->valor = aux->valor;
    ini->prox = aux->prox;

    while ( aux->prox != NULL && aux->prox->valor != x ) {
        aux = aux->prox;
    }
    
    if ( aux->prox->valor == x ) {
        LInt copia = aux->prox;
        aux->prox->prox =ini;
        aux->prox = aux->prox->prox;
        *l = copia;
        r = 1; 
    }
    return r;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//   4
typedef struct nodo {
    int valor;
    struct nodo *pai, *esq, *dir;
} *ABin;


int freeAB(ABin a) {
    if (a == NULL ) return 0;
    Abin esq2, dir2; // quero copiar o apontador, não quero alocar espaço para as coisas
    esq2 = a->esq;   
    dir2 = a->dir;   
    free(a);
    return 1 + freeAB (esq2) + freeAB (dir2);
}

int freeAB2(ABin a) {
    if (a == NULL ) return 0;
    int e = freeAB (a->esq);
    int d = freeAB (a->dir);
    free(a);
    return 1 + e + d;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//   5

void strrev ( char s[] ) {
    int t = strlen (s);
    for ( int i = 0; i < t/2 ; i++ ) {
        swap (s, i , t-i);
    }
}

void caminho(ABin a) {
    char c[500] = "";
    while (a-> pai  != NULL) {
        if ( (a->pai)->esq->valor == a->valor ) {
      //if ( (a->pai)->esq  == a  ) {
            strcat(c,"\nqse");
        }   
        if ( (a->pai)->dir->valor == a->valor ) {
      //if ( (a->pai)->dir  == a  ) {
            strcat(c,"\nrid");
        }   
        a = a->pai;
    }    
    strrev(c);
    printf("%s",c);
}

int main () {
    sumhtpo(10);
    return 0;
}

