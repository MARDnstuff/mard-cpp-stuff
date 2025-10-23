#include <stdio.h>
#include <stdlib.h>
#include "elemC.h"
#include "ColaCirP.h"

int main()
{
    int p;
    Circular c = nuevac();
    c = formarP(c, 1, 1);
    c = formarP(c, 5, 5);
    c = formarP(c, 4, 4);
    c = formarP(c, 3, 3);
    c = formarP(c, 3, 3);
    c = formarP(c, 6, 6);
    // c=rotar(c);

    ImpElem(primeroc(c));

    return 0;
}
