#include <stdio.h>
#include <stdlib.h>
#include "elemC.h"
#include "colaPro.h"

int main()
{
    Cola q = nueva();

    q = formar(formar(formar(nueva(), 1), 2), 3);
    esnueva(q) ? puts("SI") : puts("NO");
    ImpElem(primero(q));
    q = desformar(desformar(q)); // solo desforma el primero
    ImpElem(primero(q));

    return 0;
}
