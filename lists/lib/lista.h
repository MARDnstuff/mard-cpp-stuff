#include "elem.h"

typedef struct Nodo
{
    Elem dato;
    struct Nodo *sig;
} *Lista;

Lista vacia() { return NULL; }

Lista cons(Elem e, Lista l)
{
    Lista t = (Lista)malloc(sizeof(struct Nodo));
    t->dato = e;
    t->sig = l;
    return t;
}

int esvacia(Lista l) { return l == NULL; }
Elem cabeza(Lista l) { return l->dato; }
Lista resto(Lista l) { return l->sig; }

int NumElemLista(Lista l)
{
    if (esvacia(l))
        return 0;
    else
        return 1 + NumElemLista(resto(l));
}
void ImpListaF(Lista l, FILE *out)
{
    if (!esvacia(l))
    {
        ImpElemF(cabeza(l), out);
        ImpListaF(resto(l), out);
    }
}
void ImpLista(Lista l) { ImpListaF(l, stdout); }

Lista PegaListas(Lista l1, Lista l2)
{

    if (esvacia(l1))
        return l2;
    else
        return cons(cabeza(l1), PegaListas(resto(l1), l2));
}

Lista InvLista(Lista l)
{
    if (esvacia(l))
        return l;
    else
        return PegaListas(InvLista(resto(l)), cons(cabeza(l), vacia()));
}

Lista InsOrd(Elem e, Lista l)
{
    if (esvacia(l))
        return cons(e, l);
    else if (EsMenor(e, cabeza(l)))
        return cons(e, l);
    else
        return cons(cabeza(l), InsOrd(e, resto(l)));
}

Lista OrdenaLista(Lista l)
{
    if (esvacia(l))
        return l;
    else
        return InsOrd(cabeza(l), OrdenaLista(resto(l)));
}

int BuscaElem(Elem e, Lista l)
{
    if (esvacia(l))
        return 0;
    if (EsIgualElem(e, cabeza(l)))
        return 1;
    else if (BuscaElem(e, resto(l)))
        return 1;
    return 0;
}

int IgualList(Lista l1, Lista l2)
{
    if (esvacia(l1) && esvacia(l2))
    {
        return 1;
    }
    else if (esvacia(l1))
    {
        return 0;
    }
    else if (esvacia(l2))
    {
        return 0;
    }
    if (EsIgualElem(cabeza(l1), cabeza(l2)))
        if (IgualList(resto(l1), resto(l2)))
            return 1;
    return 0;
}

int EsPalindrome(Lista l)
{
    if (esvacia(l))
        return 0;
    else if (IgualList(l, InvLista(l)))
        return 1;

    return 0;
}
