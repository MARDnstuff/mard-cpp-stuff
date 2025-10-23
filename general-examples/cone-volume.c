#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1416
/*
   Programa: Ejercicio 2
   Proposito: Calcular la superficie y volumen de un cono
*/
int main()
{
   float radio, h;
   float Ab, g, Al, V, S;

   printf("\n\t ***Este programa se encarga de Calcular*** \n\t la superficie y el volumen de un cono");
   printf("\n\n\t Dame la magnitud del radio");
   printf("\n\t radio = ");
   scanf("%f", &radio);
   Ab = PI * pow(radio, 2);
   printf("\n\t El area de la base es %.4f u^2 ", Ab);
   
   printf("\n\t Ahora calculamos el volumen");
   printf("\n\t Dame la medida de la altura");
   printf("\n\n\t h= ");
   scanf("%f", &h);
   V = ((Ab * h) / 3);
   printf("\n\t El volumen de el cono es %.2f u^3", V);
   
   printf("\n\t Ahora calculemos a la variable g");
   g = sqrt((pow(h, 2)) + (pow(radio, 2)));
   printf("\n\n\t El valor de g es igual a %.2f u", g);
   
   printf("\n\n\t Es momento de calcular el Area lateral del cono");
   Al = PI * radio * g;
   printf("\n\t El area lateral del cono es de %.2f u^2", Al);
   
   printf("\n\t Ahora sacaremos  la superficie del cono");
   S = Ab + Al;
   printf("\n\t La superficie del cono es de %.2f u^2", S);
   
   printf("\n\n\t **DATOS**");
   printf("\n\t r = %.4f u", radio);
   printf("\n\t Ab= %.4f u^2", Ab);
   printf("\n\t h = %.4f u", h);
   printf("\n\t V = %.4f u^3", V);
   printf("\n\t g = %.4f u", g);
   printf("\n\t Al= %.4f u^2", Al);
   printf("\n\t S = %.4f u^2\n", S);
   
   printf("\n\n\t **DATOS REQUERIDOS**");
   printf("\n\t El volumen del cono es %.4f u^3", V);
   printf("\n\t La superficie del cono es %.4f u^2", S);
   printf("\n\n\t GRACIAS POR PARTICIPAR \n\n");
   return 0;
}
