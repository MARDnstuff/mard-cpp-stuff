#include <stdio.h>
#include <stdlib.h>
/*
   Programa: Ejercicio 7
   Proposito: Identifica  si el dato recibido es letra mayuscula o minuscula, numero y simbolo
*/

int main()
{
   char x;
   printf("\n\t ESTE PROGRAMA IDETIFICA SI EL DATO RECIBIDO \n\t ES LETRA MAYUSCULA O MINUSICULA,NUMERO Y SIMBOLO \n\t");
   printf("\n\n\t Dame un caracter:     \a");
   scanf("%c", &x);
   (x >= 'a' && x <= 'z') ? printf("\n\t Es una letra minuscula") : 0;
   (x >= 'A' && x <= 'Z') ? printf("\n\t Es una letra mayuscula") : 0;
   (x >= '0' && x <= '9') ? printf("\n\t Es un numero") : 0;
   (x >= '!' && x <= '/') ? printf("\n\t Es un simbolo") : 0;
   (x >= ':' && x <= '@') ? printf("\n\t Es un simbolo") : 0;
   (x >= '[' && x <= '.') ? printf("\n\t Es un simbolo") : 0;
   printf("\n\t GRACIAS POR PARTICIPAR");
   return 0;
}
