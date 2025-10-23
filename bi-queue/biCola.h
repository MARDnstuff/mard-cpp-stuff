/* Espec BiCola:
	nuevaB:->BiCola;
	formarBi:Elem,BiCola->BiCola;
	formarBd:BiCola,Elem->Bicola;
	esnuevaB:BiCola->Bool;
	izquierdoB:BiCola->Elem;
	derechoB:BiCola->Elem;
	desformarBi:BiCola->BiCola;
	desformarBd:BiCola->BiCola;

Axiomas: Elem e1,e2;BiCola q;
[b1] esnuevaB(nuevaB())=True;
[b2] esnuevaB(formarBi(e1,q1))=False;
[b3] esnuevaB(formarBd(q1,e1))=False;
[b4] izquierdoB(nuevoB())=ERROR;
[b5] izquierdoB(formarBi(e1,q1))=e1;
[b6] izquierdoB(formarBd(q1,e1))= SI esnuevaB(q1) return e1;
				  si no, return izquierdoB(q1);
[b7] derechoB(nuevoB())=ERROR;
[b8] derechoB(formarBi(e1,q1))=Si esnuevaB(q1) return e1
				si no, return derechoB(q1);
[b9] derechoB(formarBd(q1,e1))=e1;
[b10] desformarBi(nuevoB())=ERROR;
[b11] desformarBi(formarBi(e1,q1))=q1;
[b12] desformarBi(formarBd(q1,e1))= si es nuevaB(q1) return q1;
					si no return formarBd(desformarBi(q1),e1):ñ
[b13] desformarBd(nuevaB())=ERROR;
[b14] desformarBd(formarBi(e1,q1))= si es nuevaB(q1) return q1;
					si no return formarBi(desformarBd(q1),e1);
[b15] desformarBd(formarBd(q1,e1))= q1; */

typedef struct Nodo
{
	Elem dato;
	struct Nodo *der;
	struct Nodo *izq;
} *ApNodo;

typedef struct CNodo
{
	ApNodo Prim;
	ApNodo Ult;
} *BiCola;

BiCola nuevaB()
{
	BiCola t = (BiCola)malloc(sizeof(struct CNodo));
	t->Prim = t->Ult = NULL;
	return t;
}

int esnuevaB(BiCola q) { return (q->Prim == NULL) && (q->Ult == NULL); }

BiCola formarBi(Elem e, BiCola q)
{
	ApNodo t = (ApNodo)malloc(sizeof(struct Nodo));
	t->dato = e;
	t->izq = NULL;
	if (esnuevaB(q))
		q->Prim = q->Ult = t;
	else
		t->der = q->Prim;
	q->Prim->izq = t;
	q->Prim = t;

	return q;
}

BiCola formarBd(BiCola q, Elem e)
{
	ApNodo t = (ApNodo)malloc(sizeof(struct Nodo));
	t->dato = e;
	t->der = NULL;
	if (esnuevaB(q))
		q->Prim = q->Ult = t;
	else
		t->izq = q->Ult;
	q->Ult->der = t;
	q->Ult = t;

	return q;
}

BiCola desformarBi(BiCola q)
{
	ApNodo t = q->Prim;

	if (q->Prim == q->Ult)
	{
		q->Prim = q->Ult = NULL;
	}
	else
	{
		q->Prim = t->der;
		q->Prim->izq = NULL;
	}

	// free(t);
	return q;
}

BiCola desformarBd(BiCola q)
{
	ApNodo t = q->Ult;

	if (q->Prim == q->Ult)
	{
		q->Prim = q->Ult = NULL;
	}
	else
	{
		q->Ult = t->izq;
		q->Ult->der = NULL;
	}

	// free(t);
	return q;
}

Elem izquierdoB(BiCola q) { return q->Prim->dato; }
Elem derechoB(BiCola q) { return q->Ult->dato; }

BiCola ImpBiColaI(BiCola q)
{
	BiCola t = nuevaB();
	while (!esnuevaB(q))
	{
		ImpElem(izquierdoB(q));
		t = formarBd(t, izquierdoB(q));
		q = desformarBi(q);
	}

	return t;
}

BiCola ImpBiColaD(BiCola q)
{
	BiCola t = nuevaB();
	while (!esnuevaB(q))
	{
		ImpElem(derechoB(q));
		t = formarBi(derechoB(q), t);
		q = desformarBd(q);
	}

	return t;
}
