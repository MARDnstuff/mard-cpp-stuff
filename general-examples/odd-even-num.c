#include <stdio.h>
#include <stdlib.h>
/*
   Programa: Ejercicio 1
   Proposito: Identifica si el numero es PAR,IMPAR o CERO
*/

int main()
{
   int a;
   printf("\n\t BIENVENIDO AL PROGRAMA PARA \n\t IDENTIFICAR SI ES PAR,IMPAR O CERO \a");
   printf("\n\n\t Dame un numero : ");
   scanf("%i", &a);
   printf("\n\t tu numero es ");
   (a == 0) ? printf("CERO") : ((a % 2 == 0) ? printf("PAR") : printf("IMPAR"));
   return 0;
}
