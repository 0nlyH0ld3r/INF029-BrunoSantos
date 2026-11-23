#include <stdlib.h>

struct node {
	int *data;
	struct node *next;
};

struct list {
	struct node *first;
	struct node *last;
	int size;
};
