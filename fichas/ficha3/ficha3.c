#include <stdio.h>
#include <math.h>
void swapM (int *x, int *y) {
    int z;
    z = *x;
    *x = *y;
    *y = z;
} 

void swap (int v[], int i, int j) {
    int z;
    z = v[i];
    v[i] = v[j];
    v[j] = z;
    //swapM(&v[i],&v[j]);
    //swapM(v+i,v+j);
} 

int soma (int v[], int n) {
    int i,soma=0;
    for(i=0;i<n;i++) 
        soma += v[i];
    return soma;
}

int soma2_aux (int v[], int n, int soma) {
    if (n==0) return soma;
    return soma2_aux (v, n-1, soma + v[n-1]);
}
int soma2 (int v[], int n) {
    return soma2_aux(v, n, 0);
}

int maximum (int v[], int n, int *m){
    *m = v[0];
    if (n >= 0) {
        for (int i = 1; i < n; i++)
            if (*m < v[i]) *m = v[i];
        return 0;
    }
    else
        return 1;
}

int maximum2 (int v[], int n, int *m) {
    if (n==-1) return *m;
    if (v[n-1] > *m) m = &v[n-1];//v+n-1
    return maximum2 (v, n-1, m);
}

void inverteArray (int v[], int n) {
    int k;
    for(k=0; k!=n/2;k++) {
        swap(v,k,n-k-1);
        //swapM(&v[k],&[n-1-k]);
        //swapM(v+k,v+ n-1-k);
    }
}

void iArray2_aux (int v[], int n, int k) {
    if (k == n/2)return;
    swap(v,k,n-k-1);
    iArray2_aux(v,n,k+1);
}
void iArray2 (int v[], int n) {
    iArray2_aux(v,n,0);
}

void quadrados (int q[], int n) {
    q[n-1] = (n-1)*(n-1);
    if (n==0) return;
    quadrados (q,n-1);
}

void quadrados3_aux (int q[], int n, int k){
    if (k==n) return;
    q[k] = pow(k-1,2) + 2*(k-1)+1;
    quadrados3_aux (q,n,k+1);
}
void quadrados3 (int q[], int n){
    quadrados3_aux(q,n,0);
}

void quadrados2 (int q[], int n){
    q[0] = 0;
    for(int i=1; i<n; i++) 
        q[i] = pow(i-1,2) + 2*(i-1)+1;
}

/*
n=0, 1
n=1, 1 1
n=2, 1 2 1
n=3, 1 3 3 1
n=4, 1 4 6 4 1     
n=5, 1 5 10 10 5 1
*/

void pascal_aux (int v[], int n) {
    int i;
    v[0] = 1;
    v[n] = 1;
    for ( i=n-1; i>0; i--){
        v[i] = v[i] + v[i-1]; 
    }
}    

void pascal (int n) {
    int k, i;
    int v[n+1];
    for( k=0; k<n; k++) { 
        pascal_aux (v,k);
        for(i=0; i<=k; i++)
            printf("%d ",v[i]);
        putchar('\n');
    }
}
int main () {
    int i;
    pascal (10);
    return 0;
}
