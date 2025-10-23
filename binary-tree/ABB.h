#include "ArBin.h"

typedef Arbin ABB;

ABB InsOrdab(Elem e, ABB a)
{
	if (esvacioab(a))
		return consab(e, vacioab(), vacioab());
	else if (Esmenor(e, raiz(a)))
		return consab(raiz(a), InsOrdab(e, izquierdoab(a)), derechoab(a));
	else
		return consab(raiz(a), izquierdoab(a), InsOrdab(e, derechoab(a)));
}
