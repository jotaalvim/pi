/* Desenhar um circulo com chars:
        re = 4  2*r+1

        (1,1) - canto superior esquerdo
        (r+1,r+1) - centro do circulo 
        (linha,coluna)
        dois pontos (x1 y1) (x2,y2)
            (x2-x1)2 +(y2-y1) <= r2
            
            (linha-r-1)^2+ (coluna-r-1)^2 <= r^2
                #
                ' '
        matriz: (2*r+1) * (2*r+1)

*/

#include <stdio.h>
#include <math.h>

int circ(int r) {
    int contador = 0;
    for (int linha=1; linha<=2*r+1; linha++){
        for (int coluna=1; coluna<=2*r+1; coluna++){
            if (pow(linha-r-1,2) + pow(coluna-r-1,2) <= pow(r,2)){
                putchar('#');
                contador++;
            }
            else
                putchar(' ');
        }
        putchar('\n');
    }
    return contador;
}

int main(){
    for (int i=3; i<=7;i++){
        printf("\n\nEste  cículo tem %d pontos.\n",circ(i));
    }
    return  0;
}
