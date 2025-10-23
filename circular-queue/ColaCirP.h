typedef struct Nodo
{
	Elem dato;
	int Prioridad;
	struct Nodo *sig;
} *Circular;

Circular nuevac() { return NULL; }
int esnuevac(Circular c) { return c == NULL; }

Elem primeroc(Circular c) { return c->sig->dato; }

Circular desformar(Circular c)
{
	Circular t = c->sig;

	if (c == c->sig)
		return nuevac();
	else
		c = c->sig->sig;

	free(t);
	return c;
}

Circular rotar(Circular c) { return c->sig; }
Circular Orden(Circular c, int k)
{
	while (c->Prioridad != k)
	{
		c = rotar(c);
	}

	return c;
}

Circular formarP(Circular c, Elem e, int e1)
{ // Cola circular,dato,nivel de prioridad
	Circular t = (Circular)malloc(sizeof(struct Nodo));
	int i = 0, j, k;
	t->dato = e;
	t->Prioridad = e1;

	if (esnuevac(c))
	{
		t->sig = t;
	}
	else if (t->Prioridad >= c->sig->Prioridad)
	{
		t->sig = c->sig;
		c->sig = t;
		t = c;
		return t;
	}
	else if (t->Prioridad <= c->Prioridad)
	{
		t->sig = c->sig;
		c->sig = t;
		return t;
	}
	else
	{
		k = c->Prioridad;
		while (!(c->Prioridad > t->Prioridad >= c->sig->Prioridad))
		{
			if (t->Prioridad == c->sig->Prioridad)
			{
				break;
			}
			c = rotar(c);
			i++;
		}
		t->sig = c->sig;
		c->sig = t;
		t = c = Orden(c, k);
	}

	return t;
}
