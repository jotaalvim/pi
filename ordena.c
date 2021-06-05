#include <stdio.h>
//BUBBLE SORT
void swap (int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int bubble (int v[], int n) {
    int i;
    int r = 0;
    for ( i = 0; i < n-1; i++) {
        if (v[i] > v[i+1]) {
            swap (v,i,i+1);
            r = 1;
        }
    }
    // r = 1 se não estiver ordenado
    return r;
}

void bubbleSort (int v[], int n) {
    int i;
    int ord = 1;
    while ( ord ) {
        ord = bubble(v,n);
    }
}

//SELECTION SORT (MINIMUM SORT)
// retorna o indice do menor elemento do array

int pmenor ( int v[], int i,int n) {
    if ( i == n ) return i;
    int pt = pmenor ( v, i+1, n);
    return v[i] < v[pt] ? i : pt;
    //int im = i;//ind menor até ao momento
    //int vm = v[i];//valor  menor
    //for (; i < n; i++) {
    //    if ( v[i] < vm ) {
    //        vm = v[i];
    //        im = i;
    //    }
    //}
    ////printf("i: %d valor meno:%d\n", im, v[im]);
    //return im;
}

void mSort ( int v[], int n) {
    int im;
    int i;
    for ( i = 0 ; i < n ; i++) {
        im = pmenor ( v , i, n);
        swap (v,i,im);   
    }
}


// MAXIMUM SORT 
int pmaior ( int v[], int i,int n) {
    if ( i == n ) return i;
    int pt = pmaior ( v, i+1, n);
    return v[i] > v[pt] ? i : pt;
}

// merge sort
// quick sort
// insertion sort
int main () {
    int v[] = { 4, 5, 1, 0, -4,3,1,9};
    int i;
    for ( i = 0; i < 8; i++) {
        printf("%d", v[i]);
    }
    printf("\n");

    //bubbleSort(v,8);
    mSort(v,8);
    
    for ( i = 0; i < 8; i++) {
        printf("%d", v[i]);
    }
    printf("\n");
    return 0;
}
