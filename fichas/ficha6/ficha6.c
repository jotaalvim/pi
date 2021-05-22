#include <stdio.h>

struct staticStack {
    int sp; //stack pointer
    int values [Max];
} STACK, *SStack;

void SinitStack (SStack s) {
    s->sp = 0;
}

int SisEmpty (SStack s) {
    return s->sp == 0;
}

int Spush (SStack s, int x) {
    int r = 0;
    if (s->sp == Max) r = 1;
    else //s->values[s->sp] = x;
         //s->sp++;
        s->values[s->sp++] = x;
    return r;
}

int Spop (SStack s, int *x) {
    r = 0;
    if (SisEmpty(s)) r = 1;
    else {
        *x= s->values[s->sp-1];
        //r = s->values[--s->sp];
        s->sp--;
        r = 0;
    }
    return r;
}

int Stop (SStack s, int *x) {
    int r =1;
    if (SisEmpty(s)) r = 1;
    else { 
        *x= s->values[s->sp-1];
        //r = s->values[--s->sp];
        s->sp--;
        r = 0;
    }
    return r;
} 

struct staticQueue {
    int front;
    int length;
    int values [Max];
} QUEUE, *SQueue;

void SinitQueue (SQueue q) {
    q->length = 0;
}

int SisEmptyQ (SQueue q) {
    return q->length == 0;
}

int Senqueue (SQueue q, int x) {
    int r = 0;
    if (q->length == Max) r = 1;
    else //s->values[q->length] = x;
         //s->sp++;
        q->values[q->length-1] = x;
        q->length --;
    return r;
}

int Sdequeue (SQueue q, int *x) {
    int r =0;
    r = 0;
    if (SisEmptyQ(q)) r = 1;
    else {
        *x= q->valueq[q->length-1];
        //r = s->values[--s->sp];
        q->length--;
        r = 0;
    }
    return r;
}
int main () {
    return 0;
}
