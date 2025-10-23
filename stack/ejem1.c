#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 1, b = 0, c = 0, d = 0;
	while ((a) || (b = b + 1) || (c = c + 1))
	{
		printf(" a=%d\tb=%d\tc=%d\n", a, b, c);
		getchar();
	}

	return 0;
}
