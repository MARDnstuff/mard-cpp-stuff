#include <stdio.h>
#include <stdlib.h>
#include "elemC.h"
#include "Cola.h"

int main()
{
	int i;
	Cola p = nueva();

	for (i = 0; i < 10; i++)
	{
		p = formar(p, i);
		ImpElem(primero(p));
		p = desformar(p);
	}

	return 0;
}
