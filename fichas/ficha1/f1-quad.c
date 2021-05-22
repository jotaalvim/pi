#include <stdio.h>
void quad (int n) {
    for (int i=0; i<5; i++){
        for (int j=0; j<5 ; j++) putchar('#');
        putchar('\n');
    }
}

void quad2 (int n) {
    int i = 0;
    int j = 0;
    while (i<n) {
        while (j<n) {
            putchar('#');
            j++;
        }
        putchar('\n');
        i++;
        j = 0;
    }
}


//printf("#####\n#####\n#####\n#####\n#####")
int main () {
    quad2(5);
    return 0;

}
