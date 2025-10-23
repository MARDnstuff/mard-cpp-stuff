#include <stdio.h>
#include <stdlib.h>
/*
   Programa: Ejercicio 4
   Proposito: Calcular la suma de 3 numeros enteros de ocupen 1 byte
*/
int main()
{
   int x, y, z, P;
   char C;
   printf("\n\t ESTE PROGRAMA SE ENCARGA DE LA SUMA \n\t DE TRES NUMEROS Y QUE SU RESULATADO OCUPE 1 BYTE");
   printf("\n\t Dame x=  ");
   scanf("%i", &x);
   printf("\n\t Dame y=  ");
   scanf("%i", &y);
   printf("\n\t Dame z=  ");
   scanf("%i", &z);
   P = x + y + z;
   C = (char)P;
   printf("\n\t El valor de la suma es  %c ", C);

   return 0;
}
