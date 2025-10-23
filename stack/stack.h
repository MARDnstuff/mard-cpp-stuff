/* Especificaciones
	empty:->Pila
	push:Elem,Pila->Pila
	isempty:Pila->Bool
	top:Pila->Elem
	pop:Pila->Pila

Axiomas: Elem e,Pila p
	[p1] isempty(empty())=True
	[p2] isempty(push(e,p))=False
	[p3] top(empty())=ERROR
	[p4] top(push(e,p))=e
	[p5] pop(empty())=ERROR
	[p6] pop(push(e,p))=p
stack=pila
*/

typedef struct Nodo
{
	Elem dato;
	struct Nodo *sig;
} *Pila;

Pila empty() { return NULL; }

Pila push(Elem e, Pila p)
{
	Pila t = (Pila)malloc(sizeof(struct Nodo));
	t->dato = e;
	t->sig = p;
	return t;
}

int isempty(Pila p) { return p == NULL; }
Elem top(Pila p) { return p->dato; }
Pila pop(Pila p) { return p->sig; }
