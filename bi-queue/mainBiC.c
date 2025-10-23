#include <stdio.h>
#include <stdlib.h>
#include "elemC.h"
#include "biCola.h"

int main()
{
    BiCola q = formarBi(5, formarBd(formarBi(3, formarBd(formarBi(1, nuevaB()), 2)), 4));

    // ImpElem(izquierdoB(q));
    // ImpElem(derechoB(q));

    q = ImpBiColaI(q);
    printf("\n"),
        q = ImpBiColaD(q);
    return 0;
}
