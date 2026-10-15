#include <stdio.h>

int main()
{
	char *a = "Á";
	printf("%d", a[0]);
	if (a[0] == -61)
		printf("Oi\n");
}
