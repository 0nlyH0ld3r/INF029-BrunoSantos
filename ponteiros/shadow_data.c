#include <stdlib.h>

struct node {
	int *data;
	int size;
};

struct header {
	struct node nodes[10];
	int t_size;
};

struct header lista = {.nodes = {0}, .t_size = 0};



int main()
{
	int *p = malloc(sizeof(int) * 20);

	{
		int *g = realloc(p, sizeof(int) * 30);
		if (g)
			p = g;
	}
}
