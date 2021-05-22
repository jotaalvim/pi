#include <stdio.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno, Turma[500];

int nota (Aluno a) {
    int smini = 0;
    int nota;
    for(int i=0; i<6;i++) smini += a.miniT[i];
    //while(i<6) smini += a.miniT[i++];
    nota = (smini*10/6*0.3)+a.teste*0.7;
    return (smini*10/6 >= 8 && a.teste >= 8) && (nota > 9) ? nota : 0;
}

// Nota:  NUNCA fazer return no meio do ciclo

int procuraNum (int num, Aluno t[], int n) {
    int i = 0;
    while(i < n && t[i].numero < num ) i++; 
    return t[i].numero == num ? i : -1;
}

void ordenaPorNum (Aluno t [], int n) {
    int k;
    int trocas = 1;
    Aluno aux;
    while (trocas) {
        trocas = 0;
        k = 0;
        while (k < n-1) {
            if (t[k].numero  > t[k+1].numero ){
                aux = t[k];
                t[k] = t[k+1];
                t[k+1] = aux;
                trocas = 1;
            }
            k++;
        } 
    }
}
//FAZER ISTO RECURSIVO


void ordenaPorNome (Aluno t [], int n) {
    int k;
    int trocas = 1;
    Aluno aux;
    while (trocas) {
        trocas = 0;
        k = 0;
        while (k < n-1) {
            if (strcmp(t[k].nome, t[k+1].nome)>0){
                aux = t[k];
                t[k] = t[k+1];
                t[k+1] = aux;
                trocas = 1;
            }
            k++;
        } 
    }
}
//FAZER ISTO RECURSIVO

void criaIndPorNum (Aluno t [], int n, int ind[]) {
    Aluno tAux[n];
    for(int i = 0; i < n; i++) tAux[i] = t[i];
    ordenaPorNum (tAux,n);
    /* ... */
} 

int main () {
    Aluno a1,a2 = {4140,"joao",{0,0,0,1,2,2}, 14.5};
    Turma t1 = {a1,a2};
    int n = t1[1].miniT[5];
    return 0;
}
