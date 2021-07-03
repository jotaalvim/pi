typedef struct nodo {
    intvalor;
    structnodo *pai,
               *esq,
               *dir;
}*ABin;

ABin next(ABin a) {
    if (a->dir != NULL ) return a->dir;
    int ori = a->valor;
    while ( a->pai != NULL && a->pai->valor < ori) {
        a = a->pai;
    }
    return a->pai;
    //if (a->pai != NULL && a->pai > ori) return a->pai;
}
