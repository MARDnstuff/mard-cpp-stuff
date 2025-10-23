#include <stdio.h>
#include <stdlib.h>
#include "elemAB.h"
#include "ArBin.h"

int main()
{
    Arbin i;
    i = consab(20, consab(3, vacioab(), vacioab()), consab(6, consab(24, vacioab(), vacioab()), vacioab()));
    ImpElem(raiz(izquierdoab(i)));
    printf("%d\n", peso(i));

    return 0;
}
