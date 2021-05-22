#include <stdio.h>
void triangulo(int n){
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++){
            putchar('#');
        }
        putchar('\n');
    }
    
    n--;
    
    for(int i=n;i>0;i--) {
        for(int j=i;j>0;j--){
            putchar('#');
        }
        putchar('\n');
    }
}

int main () {
    triangulo(5);
    return(0);
}
