/* Espec Arbol binario (Arbin):

vacioab:->Arbin;
consab:Elem,Arbin,Arbin->Arbin;
esvacioab:Arbin->Bool;
raiz:Arbin->Elem;
izquierdoab:Arbin->Arbin;
derechoab:Arbin->Arbin;

Axiomas:Elem r,Arbin i,d;

[ab1] esvacioab(vacioab())=true;
[ab2] esvacioab(consab(r,i,d))=false;
[ab3] raiz(vacioab())=ERROR;
[ab5] raiz(consab(r,i,d))=r;
[ab5] izquierdoab(vacioab())=ERROR;
[ab6] izquierdoab(consab(r,i,d))=i;
[ab7] derechoab(vacioab())=ERROR;
[ab8] derechoab(consab(r,i,d))=d;*/

typedef struct Nodo
{
	Elem r;
	struct Nodo *i;
	struct Nodo *d;
} *Arbin;

Arbin vacioab() { return NULL; }

Arbin consab(Elem r, Arbin i, Arbin d)
{
	Arbin t = (Arbin)malloc(sizeof(struct Nodo));
	t->r = r;
	t->i = i;
	t->d = d;
	return t;
}

int esvacioab(Arbin a) { return a == NULL; }

Elem raiz(Arbin a) { return a->r; }

Arbin izquierdoab(Arbin a) { return a->i; }

Arbin derechoab(Arbin a) { return a->d; }

int peso(Arbin a)
{
	if (esvacioab(a))
		return 0;
	else
		return 1 + peso(izquierdoab(a)) + peso(derechoab(a));
}

void ImpPreorder(Arbin a)
{
	if (!esvacioab(a))
	{
		ImpElem(raiz(a));
		ImpPreorder(izquierdoab(a));
		ImpPreorder(derechoab(a));
	}
}

void ImpInorder(Arbin a)
{
	if (!esvacioab(a))
	{
		ImpInorder(izquierdoab(a));
		ImpElem(raiz(a));
		ImpInorder(derechoab(a));
	}
}

void ImpPostorder(Arbin a)
{
	if (!esvacioab(a))
	{
		ImpPostorder(izquierdoab(a));
		ImpPostorder(derechoab(a));
		ImpElem(raiz(a));
	}
}

int mayor(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int Altura(Arbin a)
{
	if (esvacioab(a))
		return 0;
	else
		return 1 + mayor(Altura(izquierdoab(a)), Altura(derechoab(a)));
}
