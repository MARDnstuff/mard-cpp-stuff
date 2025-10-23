#include "lib/lista.h"

int main(){
    Elem e;
    Lista l3=vacia();
    Lista l2=vacia();
    Lista l=vacia();
    Lista l4=vacia();
    //construye lista
    l4=cons(2,cons(0,cons(2,vacia())));
    l=cons(2,cons(4,cons(10,vacia())));
    l3=cons(2,cons(4,cons(10,vacia())));
    printf("\n\t Verifica si la lista esta vacia (l) \n");
    esvacia(l)?puts("Si\n"):puts("No\n");
    printf("\n\t Verifca si la lista  esta vacia (vacia())\n");
    esvacia(vacia())?puts("Si\n"):puts("No\n");
    printf("\n\t Impresion Elemento cabeza()\n");
    ImpElem(cabeza(l));
    printf("\n\t Numeros de Elemento de la Lista (l)\n");
    ImpElem(NumElemLista(l));
    printf("\n\t Impresion Lista (l)\n");
    ImpLista(l);
    printf("\n\t Impresion Lista (l3)\n");
    ImpLista(l3);
    printf("\n\t Pegar lista \n");
    ImpLista(PegaListas(l,l3));
    printf("\n\t Invertir Lista\n");
    ImpLista(InvLista(PegaListas(l,l3)));
    printf("\n\t Insertar ordenado\n");
    l2=InsOrd(24,InsOrd(6,InsOrd(27,InsOrd(17,InsOrd(13,InsOrd(6,vacia()))))));
    ImpLista(l2);//para que el dato sea guardado debe ser asignado a una lista X,con insord solamente lo acomoda pero si despues
    //quieres meter otro por separado , el anterior no existe
    printf("\n\t Lista ordenada\n");
    ImpLista(OrdenaLista(PegaListas(l,l3)));
    printf("\n\t Busqueda de elemento en la lista , SI[1] - NO[0]");
    printf("\n %i ",BuscaElem(3,l3));
    printf("\n\t Listas Iguales ? Si[1] - NO[0] ");
    printf("\n %i ",IgualList(l,l3));
    printf("\n\t Es palindrome? Si[1] - NO[0] ");
    printf("\n %i\n",EsPalindrome(l4));
    return 0;
}
