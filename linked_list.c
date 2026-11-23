#include <stdlib.h>

struct list {
	int data;
	struct list *next;
};

void append(int x, struct list **l)
{
	struct list *n = *l;


	while (n) {
		n = n->next;
	}

	n = malloc(sizeof(struct list));
	n->data = x;
	n->next = NULL;
}


struct list get(int pos, struct list l)
{
	while (l.next) {
		if (!pos)
			return l;
		l = *l.next;
		--pos;
	}

	return (struct list){0};
}

void delete(int pos, struct list **l)
{
	struct list *n = *l;
	struct list *p = NULL;

	while (n) {
		if (!pos) {
			break;
		}

		p = n;
		n = n->next;

		--pos;
	}

	if (p) {
		p->next = NULL;
	}

	free(n);
	n = NULL;
}
