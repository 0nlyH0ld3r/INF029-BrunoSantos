#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_CAPACITY 10

typedef struct {
	char* data;
	int count;
} string_view;

typedef struct {
	char* original;
	size_t capacity;
	size_t count;
} header;

string_view sv(const char* src);
void sv_input(string_view* string);
int sv_len(string_view string);
void chop_right(string_view* string, int count);
void chop_left(string_view* string, int count);
void trim_spaces(string_view* string);

string_view sv(const char* src) {
	string_view string = {.count = strlen(src)};
	char* ptr = malloc(string.count + 1);
	strncpy(ptr, src, string.count);
	string.data = ptr;

	return string;
}

void chop_right(string_view* string, int count) {
	(string->count) -= count;
}

void chop_left(string_view* string, int count) {
	(string->data) += count;
	(string->count) -= count;
}

void trim_spaces(string_view* string) {
	while (string->data[0] == ' ') {
		chop_left(string, 1);
	}

	while (string->data[string->count-1] == ' ') {
		chop_right(string, 1);
	}
}

int sv_len(string_view string){
	return string.count;
}

void sv_input(string_view* string) {
	char buffer[1000];
	if(fgets(buffer, 1000, stdin) == NULL) {
		puts("\nErro durante a leitura!\n");
		exit(1);
	}

	if (string->data != NULL) free(string->data);
	buffer[strcspn(buffer, "\n")] = '\0';

	*string = sv(buffer);
	return;
}

#if NOW_THE_VECTORS
#endif

#define init_vec(arr, x) \
	       do {\
		       if ((arr) == NULL) {									\
			       header* header = malloc(sizeof((*arr)) * ARRAY_CAPACITY + sizeof(header));	\
			       header->count = 0;								\
			       header->count = ARRAY_CAPACITY;							\
			       (arr).data = (void*)(header+1);							\
		       }											\
		       header* header = (header*)(arr) - 1;							\
		       if (header->count >= header->capacity) {							\
			       capacity *= 2;									\
			       header = realloc(header, capacity * sizeof(*arr) + sizeof(header));		\
			       (arr) = (void*)(header+1);							\
		       }											\
		       (arr)[++count] = (x);									\
	       } while(0)

int main() {
	string_view string = sv("   Hello World!   ");
	trim_spaces(&string);
	printf("%d\n", string.count);
	printf("%.*s\n", string.count, string.data);
	sv_input(&string);
	printf("%d\n", string.count);
	printf("%.*s\n", string.count, string.data);
}



