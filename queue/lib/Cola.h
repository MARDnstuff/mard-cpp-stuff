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

#include "lista.h"

typedef Lista Cola;

int esnueva(Cola q) { return esvacia(q); }

Cola nueva() { return vacia(); }

Cola formar(Cola q, Elem e)
{
  if (esnueva(q))
    return cons(e, q);
  else
    return cons(cabeza(q), formar(resto(q), e));
}
Elem primero(Cola q) { return cabeza(q); }

Cola desformar(Cola q) { return resto(q); }
