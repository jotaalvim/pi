#include <stdio.h>
float multaux (int n,float m, float r) {
    if (n == 0) return r;
    return multaux (n-1, m, r+m);
}
float multInt1 (int n, float m) {
    float r = 0;
    return multaux(n,m,r);
}

float multInt1_2 (int n, float m) {
    float r = 0;
    while (n > 0); {
        r+=m;
        n++;
    }
    return r;
}

float mult2aux (int n,int m, float r) {
    if (n == 0) return r;
    if (n%2==0) return multaux (n/2, m*2, r);
    else return multaux (n/2, m*2, r+m);
}
float multInt2 (int n, float m) {
    float r = 0.0;
    return mult2aux(n,m,r);
}

float multInt2_2 (int n, float m){
    float r = 0.0;
    while( n > 0 ){
        if (n % 2 != 0 ) r += m;
        m *= 2;
        n /=2;
    }
    return r;
}
float multInt3 (int n, float m,int *count){
    *count = 0;
    float r = 0.0;
    while( n > 0 ){
        if (n % 2 != 0 ) {
            r += m;
            (*count)++;
        }
        m *= 2;
        n /=2;
    }
    return r;
    //multInt3(a,b,&c)
}
/////////////////////////////////////////////////////////

int mdcaux(int a,int b,int c) {
    if (a%c == 0 && b%c ==0) return c;
    else return mdcaux(a,b,c-1);
}
int mdc1 (int a, int b) {
    return mdcaux(a,b,a>b?b:a);
}

void swap (int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int mdc2 (int a, int b) {//acho que nao dava 
    if (a<b) swap(&a,&b);//não vejo b%b=0
    while ((a%b!=0) && (b>1)) b--;
    return b;
}

int mdc3 (int a, int b) {
    int divisor;
    if (a<b) divisor = a;
    while (((a%divisor!=0) || (b%divisor!=0)) && (divisor>1)) b--;
    return divisor;
}

int mdc4 (int a, int b) {
    while (a!=b) {
        if (a<b) b = b-a;
        else a = a-b;
    }
    return a;
}

int mdc5 (int a, int b) {
    if (a>b) return mdc5 (a-b,b);
    if (a<b) return mdc5 (a,b-a);
    return a;
}

int mdc6 (int a, int b, int *count) {
    *count = 0;
    while (a!=b) {
        if (a<b) b = b-a;
        else a = a-b;
        (*count)++;
    }
    return a;
}

/////////////////////////////////////////////////////

int fib (int n) {
    if (n < 2) return 1;
    return fib(n-1) + fib(n-2);
    //else return fib(n-1) + fib(n-2);
}

int ffaux(int a, int b, int n) {
    if (n==0) return a;
    if (n==1) return b;
    return ffaux(b,b+a,n-1);
}
int fastfib(int n) {
    return ffaux(0,1,n);
}

int fastfib2(int n) {
    int a=0, b=1,c=0, e;;
    while (c!=n) {
        e = a;
        a = b;
        b = e+b;
        c++;
    }
    return a;
}

/////////////////////////////////////////////////////
int main (){
    //printf("%f\n",multaux2(10,5,0));
    //printf("%f",multaux(10,5,0));
    //printf("%f",multInt1(10,5));
    //printf("%f",multInt2(10,5));
    //printf("%d\n",mdc1(20,12));
    //printf("%d",mdc2(20,12));
    //printf("%d\n", mdc4(20,12));
    printf("%d\n", fastfib2(7));
    return 0;
}
