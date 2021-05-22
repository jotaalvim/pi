#include <stdio.h>

void triangulo2(int n) {
    int i,j,k;
    for(i=0; i<n; i++) {
        for(j=0; j<n-i; j++)
            putchar(' ');
        for(k=0; k<(2*i-1); k++)
            putchar('*');
        putchar('\n');
    }
}

int main () {
    triangulo2 (50);
    return 0;
}
