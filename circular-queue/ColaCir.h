typedef struct Nodo
{
    Elem dato;
    struct Nodo *sig;
} *Circular;

Circular nuevac() { return NULL; }

Circular formarc(Circular c, Elem e)
{
    Circular t = (Circular)malloc(sizeof(struct Nodo));
    t->dato = e;
    if (esnuevac(c))
        t->sig = t;
    else
    {
        t->sig = c->sig;
        c->sig = t;
    }

    return t;
}

int esnuevac(Circular c) { return c == NULL; }

Elem primeroc(Circular c) { return c->sig->dato; }

Circular desformar(Circular c)
{
    circular t = c->sig

                 if (c == c->sig) return nueva();
    else c = c->sig->sig;

    free(t);
    return c;
}

Circular rotar(Circular c) { return c->sig; }
