#include <stdio.h>

void xadrez (int n){
    for (int i=0; i<n ; i++){
        for(int j=0;j<n;j++) {
            if ( (i+j) % 2 == 0) putchar ('#');
            else putchar('_');
        }
        putchar('\n');
    }
}

int main () {
    xadrez(5);
    return 0;
}
