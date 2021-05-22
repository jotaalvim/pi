#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int vogal (char c) {
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
       c=='A'||c=='E'||c=='I'||c=='O'||c=='U') 
        return c;//!=0
    return 0;
}

int contaVogais (char *s) {
    int c=0;
    while (*s) {
        if(vogal (*s)) c++;
    //for(i=0; s[i]!='\0' ;i++){
    //    if(vogal (s[i])) c++;
    //}
    return c;
}

int contaVogais_2(char *s) {
    if (!*s) return 0;//*s == '\0'
    if (vogal(*s))  return 1 + contaVogais_2(s+1); 
    return contaVogais_2(s+1);//++s 
}

//////////////////////////////////////////////////////
int vogalRepetida (char *s){
    int vogRep=1, i;
    char paragem = s[0];
    for (i = 1; s[i] == paragem; i++) vogRep++;
    return vogRep;
}

int retiraVogaisRep (char *s){
    int i, p=0, contaVogRep=0;
    char aux [strlen(s)+1];
    i = 0;
    while (s[i] != '\0'){
        aux [p] = s[i];
        if (vogal(s[i]) && s[i] == s[i+1]) {
            contaVogRep ++;
        }
        else{
           aux[p] = s[i];
           p++;
        }
        i++;// adicionei a medida
    }
    aux [p] = '\0';
    strcpy (s,aux);
    return contaVogRep;
}

int retiraVogaisRep_2 (char*s) {
    int a=1; b=1;
    while (s[b]) {
        if (!vogal(s[b]) || (s[b] != s[b-1])){
            s[a] == s[b];
            a++;
        }
        b++;
    }
    s[a] = '\0';
    return b-a;
}

/*
int duplicaVogais (char*s) {
    int a =1; p=0; contaVogAc = 0;
    char aux [strlen(s)*2+1];
    i=0;
    
    while (s[b]) {
        if (vogal(s[i])){
            aux[p] = s[i];
            p++;
            aux[p] = s[i];
            p++;
            contaVogAc ++;
        }
        else {
            aux[p] = s[i];
            p++;
        }
        i++;
    }
    s[a] = '\0';
    return b-a;
}
*/

int duplicaVogais_2 (char*s) {
    int j, comp = 0, i = 0, vogais = 0;
    //calcular tamanhos
    while(s[i]) {
        comp++;
        if (vogal(s[i])) vogais++;
        i++;
    }
    //processar a string
    i = comp -1;
    j = comp + vogais -1;
    while (i>=0) {
        s[j] = s[i];
        j--;
        if (vogal(s[i])) {
            s[j] = s[i];
            j--;
        }
        i--;
    }
    s[comp+vogais] = '\0';
    return vogais;
}

int main () {
    //char *palavra, *pla2;
    //palavra = (char*) malloc (sizeof (char) *4);
    //strcpy(palavra,"ola");
    //pal2 = strdup("isto  é uma aula...");
    
    //char s[5] ="aaaa";
    //printf("%d",contaVogais_2("ola"));
    
    //printf("%d",retiraVogaisRep (s));
    return 0;
}
