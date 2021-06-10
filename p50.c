#include <stdio.h>
#include <string.h>

int p1() {
    int x,max;
    scanf("%d",&x);
    max = x; 
    while(x != 0) {
        scanf("%d",&x);
        if (x > max)
            max = x;
    }
    return max;
}

int p1_2aux(int m) {
    int x;
    printf("digame um");
    scanf("%d",&x);
    if (x==0)
       return m;
    return p1_2aux( x>m ? x:m );
}
int p1_2() {
    int x;
    printf("digame um");
    scanf("%d",&x);
    return p1_2aux(x);
}

///////////////////////////////////////////////////////
int p2() {
    int x,soma,contador=1;
    scanf("%d",&x);
    soma = x;
    while(x != 0) {
        scanf("%d",&x);
        soma += x;   
        if (x) contador++; // !!!!!!!!!!!!!!!!!!!!!  se n for 0 então é false
    }
    printf("soma = %d, lidos = %d\n", soma, contador);
    printf("a média dos números lidos  doi %.2f\n", (float)soma/contador);
    return 0;
}

///////////////////////////////////////////////////////
int p3() {
    int n,maior,segundo;
    scanf("%d",&n);
    maior = n; 
    scanf("%d",&n);
    if(n>maior) {
        segundo = maior;
        maior = n;
    }
    else 
        segundo = n;
    while(n!=0){
        scanf("%d",&n);
        if(n>maior) {
            segundo = maior;
            maior = n;
        }
        else if(n> segundo)
                 segundo = n;
    }
    printf("o segundo maior foi %d\n", segundo);
    return 0;
}

///////////////////////////////////////////////////////
int p4_aux(int n){
    int res = 0;
    while (n>0) {
        if (n%2 !=0) res++;
        n = n / 2;
    }
    return res;
}
int p4() {
    for (int i=0;i<=1000;i++)
        printf("% 4d - %d\n",i , p4_aux(i));
    return 0;
}

///////////////////////////////////////////////////////
int p5_aux(int n){
    int res = 0;
    while (n>0) {
        if (n%2 == 0) res++;
        n = n / 2;
    }
    return res;
}
int p5() {
    for (int i=0;i<=1000;i++)
        printf("% 4d - %d\n",i , p5_aux(i));
    return 0;
}

///////////////////////////////////////////////////////
int p6 (unsigned int n) {
    int c=0;
    for (c=0;n>=1;c++)
        n /= 10;
    return c;
}

///////////////////////////////////////////////////////
char *p7(char s1[], char s2[]) { //strcat 
    int i=0, c=0;
    while (s1[c] != '\0') c++;
    while (s2[i] != '\0') {
        s1[c] = s2[i];
        c++;
        i++;
    }
    s1[c] = '\0';
    return s1;
}

char *p7_2(char s1[], char s2[]) { //strcat 
    int i, c;
    for (c=0; s1[c]!='\0'; c++) {}
    for (i=0; s2[i]!='\0'; c++,i++) 
        s1[c] = s2[i];
    s1[c] = '\0';
    return s1;
}

char *p7_3_aux (char s1[],char s2[],int i,int j) {
    if (s1[i]=='\0') {
        s1[i] = s2[j];
        return p7_3_aux(s1,s2,i+1,j+1);
    }
    if (s2[j]=='\0') {
        s1[i] = '\0';
        return s1;
    }
    return p7_3_aux(s1,s2,i+1,j);
}//recursiva
char *p7_3(char s1[], char s2[]) {
    return p7_3_aux(s1,s2,0,0);
}

///////////////////////////////////////////////////////
char *p8(char *s1, char s2[]) { // s2 > source
    int i;
    for(i=0; s2[i]!='\0';i++) 
        s1[i] = s2[i];
    s1[i+1] = '\0';
    return s1;
}

///////////////////////////////////////////////////////
int p9 (char s1[], char s2[]){// strcmp
    int i=0;
    //while  (s1[i] - s2[i] == 0) {
    //    if (s1[i] =='\0') return 0;
    //    i++;
    //}
    for (int i = 0; s1[i] - s2[i] == 0; i++)
        if (s1[i] =='\0') return 0;
    return (s1[i] - s2[i]);
}

int p9_2 (char *s1, char *s2){ // strcmp
    if (*s1-*s2 == 0 && *s1=='\0') return 0;
    //if ( !*s1-*s2 && !*s1) return 0;
    if (*s1-*s2 == 0) return p9_2 (s1+1, s2+1);  
    return (*s1- *s2);
}

///////////////////////////////////////////////////////
int prefixo_aux (char *s1, char *s2, int n) {//s1 é prefixo de s2?
    if (!*s1) return n; //if (*s1 == '\0') return 1;
    if (*s1 == *s2) return prefixo_aux (s1+1,s2+1,n+1);
    return n;
}
int prefixo (char *s1, char *s2) {
    int t = strlen(s2);
    //printf("\n> %d %d\n",prefixo_aux(s2,s1,0),t);
    return (t == prefixo_aux(s2,s1,0));
}

int prefixo2 (char *s1, char *s2) {//s1 é prefixo de s2?
    if (!*s1) return 1; //if (*s1 == '\0') return 1;
    if (*s1 == *s2) return prefixo2 (s1+1,s2+1);
    return 0;
}

int prefixo3 (char s1[],char s2[]) {
    int i;
    while (*(s1+i) && s2[i] == s1[i]) i++;
    //for (i=0;s1[i]!='\0'&& s2[i] ==s1[i]; i++);
    //for (i=0;*(s1+i)&& *(s1+i)==*(s2+i); i++);
    return (s1[i]=='\0');
}

char *p10 (char s1[], char s2[]) { //strstr
    while (*s1){ // *s1 != '\0'
        if (prefixo3(s2,s1)) return s1;
        s1++;
    }
    return NULL;
}

///////////////////////////////////////////////////////
void swap (char *a, char *b) {
    char z=*a;
    *a = *b;
    *b = z;
}

void p11 (char s[]) {//strrev
    int t = strlen(s);
    for (int i=0; i<t/2; i++) 
        swap(s+i,s+t-i-1);
}

///////////////////////////////////////////////////////
void p12 (char s[]) {//strnoV
    int i = 0,k = 0;
    while (s[k]!='\0'){
        //if(s[k]=='a'|| s[k] =='i'||s[k]=='e'||s[k]=='k'||s[k]=='o'||s[k]=='u'||s[k]=='A'||s[k]=='E'||s[k]=='I'||s[k]=='O'||s[k]=='U') k++;
        if (strchr("aeiouAEIOU",s[k])) k++;
        else {
            s[i] = s[k];
            k++;
            i++;
        }
    }
    s[i] = '\0';
}
///////////////////////////////////////////////////////
void p13 (char t[], int n) {//truncW
    //:s/\(\w\w\w\)\w*/\1/g
    int estado = 1, c = 0;
    char *k = t;
    while (*k) {
        switch(estado) {
            case 1:
                if (*k == ' ') {
                    estado = 3;
                    c = 0;
                }
                else 
                if (c != n) {
                    *t = *k;
                    t++;
                    k++;
                    c++;
                }
                else {
                    estado = 2;
                    c = 0;
                }
                break;
            case 2://aqui o c = 0
                if (*k == ' ') estado = 3;
                else k++;
                break;
            case 3:
                if (*k == ' ') {
                    *t = *k;
                    k++;
                    t++;
                }
                else {
                    estado = 1;
                    *t = ' ';
                    t++;
                }
                break;
        }
    }
    *t = '\0';
}
// FIXME NAO FUNCIONA NA BB
//usar strtok FIXME

///////////////////////////////////////////////////////
//devolve o índice do maior valor de array
int maximo(int k[], int n) {
    int i = 0; 
    int v = k[0];
    int imax = 0;
    while (i<n) {
        if (k[i] > v) {
            v = k[i];
            imax = i;
        }
        else i++;
    }
    return imax;
}

char p14 (char s[]){//charMaisfreq 
    int k[256] = {0}; /// preenche tudo com 0
    //s = strlwr(s);
    if (!*s) return 0;
    else 
    while (*s) {
        k[*s] += 1;
        s++;
    }
    return maximo(k,256);
}


///////////////////////////////////////////////////////
int p15 (char t[]) {//iguaisConsecutivos
    int max = 0, c = 0, i;
    for (i = 0; t[i]!='\0'; i++) {
        c++;
        if (t[i] != t[i+1]) {
            max = c > max ? c : max;
            c = 0;
        }
    }
    return max;
}


///////////////////////////////////////////////////////
int p16 (char t[]) {//difConsecutivos
    int max = 0, c = 0, i;
    for (i = 0; t[i]!='\0'; i++) {
        c++;
        if (t[i] == t[i+1]) {
            max = c > max ? c : max;
            c = 0;
        }
    }
    return max;
}
//FIXME NAO FUNCIONA NA CB

////////////////////////////////////////////////////////
int p17_aux (char s1[], char s2[], int n) {
    if (*s1 == *s2 && *s2 && *s1) return p17_aux(s1+1,s2+1,n+1);
    return n;
}
int p17 (char s1 [], char s2 []) {//maiorPrefixo
    return p17_aux(s1,s2,0);
}

int p17_2 (char s1 [], char s2 []) {//maiorPrefixo
    int c = 0;
    while (*s1 && *s2 && *s1 == *s2) {
        c++;
        s1++;
        s2++;
    }
    return c;
}

///////////////////////////////////////////////////////
int p18(char s1 [], char s2 []){ //maiorSufixo
    int c = 0;
    s1 += strlen(s1)-1;
    s2 += strlen(s2)-1;
    while (*s1 && *s2 && *s1 == *s2) {
        c++;
        s1--;
        s2--;
    }
    return c;
}


///////////////////////////////////////////////////////
int p19 (char s1[], char s2[]) { //sufPref
    int max = 0,n;
    while (*s1) {
        if (prefixo3(s1,s2)) {
            n = p17_2(s1,s2);
            max = max > n ? max : n;
        }
        s1++;
    }
    return max;
}

int p19_2 (char s1[], char s2[]) { //sufPref
    int i, j = 0, r = 0;
    for( i = 0; s1[i]; i++){
        if( s1[i] == s2[j] ){
            r++;
            j++;
        }
        else {
            r = 0;
            j = 0;
        }
    }
    return r;
}

///////////////////////////////////////////////////////
int p20 (char s[]) { //contaPal
    int n = 0;
    int et = 1;
    if (s[0]!=' ' && *s && s[0]!='\n' ) n = 1;
    while (*s) {
        switch (et) {
        case 1:
            if (*s == ' ' || *s == '\n') { 
                et = 2;
            }
            break;
        case 2:
            if (*s != ' ' && *s != '\n') {    
                et = 1;
                n += 1;
            }
            break;
        }
        s++;
    }
    return n;
}
//usar strtok

int contaPal (char s[]) {
	int i,acc = 0;
	for (i = 0;s[i] != '\0';i++) {
		if (s[i]!=' '&&s[i]!='\n'&&(s[i-1]==' '||s[i-1]=='\0')) acc++; // Esta parte vai ver se dps de uma letra ha um espaco;
	}
	return acc;
}


///////////////////////////////////////////////////////
int p21 (char s[]) {//contaVogais
    int n = 0;
    while (*s) {
        if (strchr("aeiouAEIOU",*s)) n += 1;
        s++;
    }
    return n;
}

///////////////////////////////////////////////////////
int p22 (char a[], char b[]){ //contida
    while ( *a && strchr(b,*a) ) a++;
    return (!*a); //*a == '\0'
}

///////////////////////////////////////////////////////
int p23 (char s[]) {//palindorome
    int t = strlen(s), i;
    int v = 1; 
    for (i = 0; i < t/2; i++) v = v && (s[i] == s[t-i-1]);
    return v;
}

///////////////////////////////////////////////////////
int p24 (char x[]) {//remRep
    char *b = x;
    int c = 1;
    if (*x == '\0') return 0;
    for (x++; *x; x++) {
        if (*x != *b) {
            c++;
            *(++b) = *x;
        }
    }
    b++;
    *b = '\0';
    return c;
}

///////////////////////////////////////////////////////
int p25 (char t[]) { //limpaEspacos
    char *b = t;
    int c = 1;
    if (!*t) return 0;
    for(t++; *t; t++) {
        if (*t != ' ' || *(t-1) != ' '){ //b++;
           *(++b) = *t;
           c++;
        } 
    } //b++; 
    *(++b) = '\0';
    return c;
}

///////////////////////////////////////////////////////
void p26 (int v[], int n, int x) {//insere
    int i;
    for(i = n-1; i >= 0 && v[i] > x; i--) {
        v[i+1] = v[i];
    }
    v[i+1] = x;
}

///////////////////////////////////////////////////////
void p27 (int r [], int a[], int b[], int na, int nb){
        int ia = 0, ib = 0;
    while (na + nb > 0) {
        if (nb == 0 || (a[ia] < b[ib]  &&  na != 0)) {
            *(r++) = a[ia++]; na--;
        }
        else
        if ( na == 0 || (b[ib] < a[ia] &&  nb != 0)) {
            *(r++) = b[ib++]; nb--;
        }
        else
        if (a[ia] == b[ib] &&  na != 0 && nb != 0 ) {
            *(r++) = a[ia++]; na--;
        }
    }
}
//FIXME

///////////////////////////////////////////////////////
int p28 (int a[], int i, int j) {//crescente
    while (i < j && a[i] <= a[i+1]) i++; 
    return i == j ? 1 : 0;
}

///////////////////////////////////////////////////////
int p29 (int v[], int n) {//retiraNeg
    int ia = 0, ib = 0;
    for(; ib < n; ib++) {
        if (v[ib] >= 0) {
            v[ia++] = v[ib];
        }
    }
    return ia;
}

///////////////////////////////////////////////////////
int p30 (int v[], int n) {//menosFreq
    int min = v[0];//minimo;
    int mocrr = n+1;//minimo de ocorrencias
    int c = 0;//nº vezes 
    for (v++; n > 0; n--, v++) {
        if ( *(v-1) == *v ) c++;
        else {
            if (mocrr > c) {
                mocrr = c;
                min = *(v-1);       
            }
        c = 0; 
        }
    }
    return min;
}

///////////////////////////////////////////////////////
int p31 (int v[], int n) {//maisFreq
    int min = v[0];//minimo;
    int mocrr = n+1;//minimo de ocorrencias
    int c = 0;//nº vezes 
    for (v++; n > 0; n--, v++) {
        if ( *(v-1) == *v ) c++;
        else {
            if (mocrr < c) {
                mocrr = c;
                min = *(v-1);
            }
        c = 0;
        }
    }
    return min;
}


///////////////////////////////////////////////////////
int p32 (int v[], int n) {//maxCresc
    int mocrr = 0;
    int c = 1;//nº vezes 
    for (v++; n > 0; n--, v++) {
        if ( *(v-1) <= *v ) c++;
        else {
            if (mocrr < c)  mocrr = c;
            c = 1;
        }
    }
    return mocrr;
}

///////////////////////////////////////////////////////
int pertence( int v[], int n, int x) {
    for( n--; n >= 0; n--) {
        if ( x == v[n]) return 1;
    }
    return 0;
}
// 1 2 3 4 4 5 
int p33 (int v[], int n) {//elimRep
    int a = 0, f = 0, c = 0;
    while (f < n ) {
        if ( pertence (v+f+1,n-f-1,v[f]) ) {
            f++;
        }
        else {
            v[a] = v[f];
            f++; a++;
        }
    }
    return f-a;
}

///////////////////////////////////////////////////////
int p34 (int f[], int n) {//elimRepOrd
    int *a = v, c = 1;
    for ( v++ ; n > 1; n--, v++) {
        if (*a != *v) {
            *(++a) = *v;
            c++;
        }
    }
    return c;
}

///////////////////////////////////////////////////////
int p35 (int a[], int na, int b[], int nb) { //comunsOr
    int c = 0;
    //while (na > 0 && nb > 0) {
    //    if (*a == *b)  {
    //        c++;
    //        a++;
    //        b++;
    //        na--;
    //        nb--;
    //    }
    //    if (*a > *b) { b++; nb--; }
    //    if (*b > *a) { a++; na--; }
    //}
    //return c;
    for ( na--, nb--; na >= 0 && nb >= 0; ) {
    if ( a[na] == b[nb] ) {
        na--; nb--; c++;
        }
        if (a[na] > b[nb]) na--;
        if (b[nb] > a[na]) nb--;
    }
    return c;
}

///////////////////////////////////////////////////////
int p36 (int a[], int na, int b[], int nb) { //comuns
    int i, c = 0;
    for(i = 0; i < na ; i++) {
        c += pertence(b, nb, a[i]);
    }
    return c;
}

///////////////////////////////////////////////////////
int p37 (int v[], int n){ //minInd
    int i, im = 0;//menor indice até ao momento
    int m = *v;//menor valor até ao momento
    for (i = 0; n > i ; i++) {
        if ( v[i] < m ) {
            m = v[i];
            im = i;
        } 
    }
    return im;
}

///////////////////////////////////////////////////////
void p38 (int v[], int ac [], int n) { //somasAc
    int i;
    *ac = *v;
    for (i = 1; i < n; i++) {
        ac[i] = ac[i-1] + v[i];
    }
}

///////////////////////////////////////////////////////
int p39 (int n, float m [n][n]) { //triSup
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++) {
           if ( j < i && m[i][j] != 0) return 0;
        }
    }
    return 1;
}

///////////////////////////////////////////////////////
void p40 (int n, float m [n][n]) { //transposta
    int i,j,aux;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            aux= m[i][j];	
			m[i][j] = m[j][i];
			m[j][i] = aux;	
        }
    } 
}

///////////////////////////////////////////////////////
void p41 (int n, int m, int a[n][m], int b[n][m]) {//addTo
    //for (n-- ; n >= 0; n--) {
    //    for (m-- ; m >= 0; m--) { m-- não volta ao que estava, sai pela borda
    //        a[n][m] += b[n][m];
    //    }
    //}    
    int i,j;
    for ( i = 0 ; i < n; i++) {
        for ( j = 0 ; j < m; j++) {
            a[i][j] += b[i][j];
        }
    }
}

///////////////////////////////////////////////////////
int p42 (int n, int v1[n], int v2[n], int r[n]) {//unionSet
    for ( ; n >= 0; n--) {
        r[n] = v1[n] || v2[n];// r[n] = (v1[n] == 1 || v2[n] == 1) ? 1 : 0;
    } // && implementação não estrita, porqueretorna o outro
}

///////////////////////////////////////////////////////
int intersectSet (int n, int v1[n], int v2[n], int r[n]) {//p43
    for ( ; n >= 0; n--) {
        r[n] = v1[n] &&  v2[n];
        //r[n] = (v1[n] == 1 && v2[n] == 1) ? 1 : 0;
    }
}

///////////////////////////////////////////////////////
int intersectMSet (int n, int v1[n], int v2[n], int r[n]) {//p44
    for ( ; n >= 0; n--) {
        r[n] = (v1[n] > v2[n] ) ? v2[n] : v1[n];
    }
}

///////////////////////////////////////////////////////
int unionMSet (int n, int v1[n], int v2[n], int r[n]) {//p45
    for ( ; n >= 0; n--) {
        r[n] = (v1[n] > v2[n] ) ? v1[n] : v2    [n];
    }
}

///////////////////////////////////////////////////////
int cardinalMSet (int n, int v[n]) { //p47
    int c = 0;
    for(n--; n >= 0; n--) {
        c += v[n];
    }    
    return c;
}


///////////////////////////////////////////////////////
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct posicao {
    int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int n) {//p47
    for (n--; n >= 0; n--) {
        switch (mov[n]) {
            case Norte: inicial.y++;break;
            case Sul  : inicial.y--;break;
            case Este : inicial.x++;break;
            case Oeste: inicial.x--;break;
        }
    }
    return inicial;
}

///////////////////////////////////////////////////////
int caminho (Posicao inicial, Posicao final, Movimento mov[], int n) {//p48
    int c = 0;
    for (; n > 0; n--) {
        if (inicial.x > final.x ) { 
            *mov = Oeste;
            inicial.x--;
        }
        else
        if (inicial.x < final.x ) {
            *mov = Este;
            inicial.x++;
        }
        else
        if (inicial.y > final.y ) {
            *mov = Sul;
            inicial.y--;
        }
        else
        if (inicial.y < final.y ) {
            *mov = Norte;
        inicial.y++;
            
        }
        else c--;
        c++;
        mov++;
    }
    if (inicial.x == final.x && inicial.y == final.y) return c;
    else 
        return -1;
}

///////////////////////////////////////////////////////
int maisCentral (Posicao pos[], int n) {//p49
    int m = 0;
    int d = pos[0].x*pos[0].x + pos[0].y*pos[0].y;
    for (n--; n >= 0; n--) {
        if(pos[n].x*pos[n].x + pos[n].y*pos[n].y < d) {
            d = pos[n].x*pos[n].x + pos[n].y*pos[n].y;
            m = n;
        }
    }
    return m;
}

///////////////////////////////////////////////////////
int vizinhos (Posicao p, Posicao pos[], int n){ //p50
    int c = 0;
    for (n--; n >= 0; n--) {
        if (p.x == pos[n].x && p.y == pos[n].y +1) c++;
		if (p.x == pos[n].x && p.y == pos[n].y -1) c++;
		if (p.y == pos[n].y && p.x == pos[n].x +1) c++;
		if (p.y == pos[n].y && p.x == pos[n].x -1) c++;
    } 
    return c;
}

///////////////////////////////////////////////////////
int main () {
    char s[]  = "Ola";
    char s2[] = "Ola Mundo Ola";
    int v[10] = {1,1,2,1,5,6,7,8,9,10};
    printf("%d\n",conta(v,10,1));
    return 0;
}


