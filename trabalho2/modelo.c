#include <stdlib.h>

	int retorno = 0;
	// a posicao pode já existir estrutura auxiliar
	// retorno = JA_TEM_ESTRUTURA_AUXILIAR;
	// // se posição é um valor válido {entre 1 e 10}
	// retorno = POSICAO_INVALIDA;
	// // o tamanho ser muito grande
	// retorno = SEM_ESPACO_DE_MEMORIA;
	// // o tamanho nao pode ser menor que 1
	// retorno = TAMANHO_INVALIDO;
	// // deu tudo certo, crie
	// retorno = SUCESSO;

typedef struct {
	int *data;
	int current_size;
	int max_size;
} Node;

typedef struct {
	Node subs[10];
	int total_size;
} List;

List vetor = {0};

int create_node(int pos, int size)
{
	--pos;

	if (pos > 9) return -1;
	if (size > 10) return -2;
	if (vetor.subs[pos].data) return -3;

	vetor.subs[pos].data = malloc(sizeof(int) * size);

	return 0;
}

int delete_node(int pos)
{
	--pos;

	if (pos > 9) return -1;


	free(vetor.subs[pos].data);

	vetor.subs[pos].data = NULL;
	vetor.subs[pos].max_size = 0;
	vetor.subs[pos].current_size = 0;

	return 0;
}

int get(int node, int pos)
{
	if (node > 9) return -4;
	if (!vetor.subs[node].data) return -6;
	if (pos > vetor.subs[node].max_size) return -1;

	return -1;
}
