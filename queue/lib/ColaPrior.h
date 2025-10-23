/* Espec Cola
  nueva:->Cola
  formar:Cola,Elem->Cola
  esnueva:Cola->Bool
  primero:Cola->Elem
  desformar:Cola->Cola

Axiomas: Cola q,Elem e
  [c1] esnueva(nueva())=cierto;
  [c2] esnueva(formar(q,e))=Falso;
  [c3] primero(nueva())=ERROR;
  [c4] primero(formar(q,e))= Si esnueva(q) return e;
        sino return primero(q);

  [c5] desformar(nueva())=ERROR;
  [c6] desformar(formar(q,e))=si esnueva(q) return q;
        sino return formar(desformar(q),e); */
// Implemenetar impresion de una cola

typedef struct Nodo
{
  Elem dato;
  Elemp Prioridad;
  struct Nodo *sig;
} *ApNodo;

typedef struct CNodo
{
  ApNodo Prim;
  ApNodo Ult;
} *Cola;

Cola nueva()
{
  Cola t = (Cola)malloc(sizeof(struct CNodo));
  t->Prim = t->Ult = NULL;
  return t;
}

int esnueva(Cola q) { return (q->Prim == NULL) && (q->Ult == NULL); }

Cola formarP(Cola q, Elem e, Elemp p)
{
  ApNodo t = (ApNodo)malloc(sizeof(struct Nodo));
  t->dato = e;
  t->Prioridad = p;
  t->sig = NULL;
  if (esnueva(q))
  {
    q->Prim = q->Ult = t;
  }
  else if (t->Prioridad < q->Ult->Prioridad)
  {
    q->Ult->sig = t;
    q->Ult = t;
  }
  else if (t->Prioridad > q->Prim->Prioridad)
  {
  }

  return q;
}

Cola desformar(Cola q)
{
  ApNodo t = q->Prim;

  if (q->Prim == q->Ult)
    q->Prim = q->Ult = NULL;
  else
    q->Prim = q->Prim->sig;

  // free(t);
  return q;
}

Elem primero(Cola q) { return q->Prim->dato; }
