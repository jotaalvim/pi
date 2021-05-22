#include "abin.h"



ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
   return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
    	m = rand() % N;
    	a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;	
}

int altura (ABin a){
    int altEsq, altDir;
    int r = 0;
    if (a != NULL) {
        if (a == NULL) r = 0;
        altEsq = altura (a->esq);
        altDir = altura (a->dir);
        if (altEsq > altDir)
            return 1 + altEsq;
        return 1+ altDir;
    }    
}

int nFolhas (ABin a){
    int r = 0;
    if (a!=NULL) {
        if (a-esq == NULL && a->dir == NULL) r = 1;
        else {
            r = nFolhas(a->esq) + nFolhas(a->dir);    
        }
    }
}

ABin maisEsquerda (ABin a){
    if (a == NULL || a-> esq == NULL) {
        return a;
    }
    return mains Esquerda(a->esq);
    
// while (a->esq != NULL) {
//     a = a->esq;
// }
// return a:
// 
}

void imprimeNivel (ABin a, int l){
    if (a!= NULL)  
}

int procuraE (ABin a, int x){
    int r = 0;
    if (a!= NULL) {
        if (a->valor == x)
            r = 1;
        else
            r = procuraE(a->esq,x) || procuraE(a->dirx);
    }
    return r;
}

struct nodo *procura (ABin a, int x){
    ABin r = NULL;
    if (a!= NULL) {
        if (a->valor == x) r = a;
        else if(x > a->valor) 
            r = procura(a->dir,x);
        else
            r = procura(a->esq,x);
    }
    r;      
}

int nivel (ABin a, int x){
}
int auxNivel(ABin a, int x, int n) {
    if (a ==NULL) {
        return -1;
    }
    if (a->valor == x) {
        return n;
    }
    else if(x < a->valor) {
        return auxNivel(a->dir,x,n+1);
        else return auxNivel(a->esq,x,n+1);
    }
}
void imprimeAte (ABin a, int x){
    
}

