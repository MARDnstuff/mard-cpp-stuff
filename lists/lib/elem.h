#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Elem;

void ImpElemF(Elem e, FILE *out) {
    fprintf(out, "%i\n", e);
}

void ImpElem(Elem e) {
    ImpElemF(e, stdout);
}

int EsMenor(Elem e1, Elem e2) {
    return e1 < e2;
}

int EsIgualElem(Elem e1, Elem e2) {
    return e1 == e2;
}
