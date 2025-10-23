#include <stdio.h>
#include <stdlib.h>
#include "elemAB.h"
#include "ABB.h"

int main()
{
    ABB a = vacioab();
    a = InsOrdab(5, InsOrdab(15, InsOrdab(25, InsOrdab(40, InsOrdab(35, a)))));
    ImpInorder(a);
}
