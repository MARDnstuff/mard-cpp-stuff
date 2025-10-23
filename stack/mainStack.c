#include <stdio.h>
#include <stdlib.h>
#include "elemS.h"
#include "stack.h"
int EsOperador(Elem);
int EsParIz(Elem);
int EsParDer(Elem);
int EsOperando(Elem);
int Prec(Elem);
void InaPos(char *);

int main(int agrc, char *argv[])
{
	char *in = argv[1]; // puede ser *(argv+1); o *++argv;
	printf("\n\tForma original: %s \n", in);
	printf("\n\tForma posfija: ");
	InaPos(in);
	getchar();
	return 0;
}

void InaPos(char *in)
{
	char c;
	int i = 0;
	Pila op = empty();
	while ((c = *(in + i)) != '\0')
	{
		if (EsOperando(c))
			putchar(c);
		else if (EsOperador(c))
			if ((isempty(op)) || (EsParIz(c)) || (Prec(top(op)) < Prec(c)))
				op = push(c, op);
			else
			{
				while ((Prec(top(op)) >= Prec(c)) && (!EsParIz(top(op))) && (!isempty(op)))
				{
					ImpElem(top(op));
					op = pop(op);
				}
				op = push(c, op);
			}
		else if (EsParIz(c))
			op = push(c, op);
		else
		{
			while (!EsParIz(top(op)))
			{
				ImpElem(top(op));
				op = pop(op);
			}
			op = pop(op);
		}

		i++;
	}

	while (!isempty(op))
	{
		ImpElem(top(op));
		op = pop(op);
	}
}

int EsOperador(Elem e)
{
	return (e == '+' || e == '-' || e == '*' || e == '/' || e == '^');
}

int EsParIz(Elem e) { return e == '('; }

int EsParDer(Elem e) { return e == ')'; }

int EsOperando(Elem e)
{
	return (!EsOperador(e) && !EsParIz(e) && !EsParDer(e));
}

int Prec(Elem e)
{
	switch (e)
	{
	case '^':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	}

	return 0;
}
