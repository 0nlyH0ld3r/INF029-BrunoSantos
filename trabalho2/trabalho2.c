#include <stdio.h>
#include <stdlib.h>
#include "trabalho2.h"

// Olha em trabalho2.h para ver sobre a estrutura
List vetor = {0};

	// Verifica se a posição dada é válida e se a estrutura naquela posição existe ou
	// não. Retorna sucesso caso a estrutura sejá válida nesses quesitos, retorna qual
	// erro foi encontrado caso seja inválida.
int verificar_estrutura(int pos);

   // Objetivo: criar estrutura auxiliar na posição 'posicao'.
   // com tamanho 'tamanho'
   //
   // Rertono (int)
   // SUCESSO - criado com sucesso
   // JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
   // POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
   // SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
   // TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
int criarEstruturaAuxiliar(int pos, int size)
{

	--pos;

	if (vetor.subs[pos].data)
		return JA_TEM_ESTRUTURA_AUXILIAR;

	if (pos > 10 || pos < 0)
		return POSICAO_INVALIDA;

	if (size > 9)
		return SEM_ESPACO_DE_MEMORIA;

	if (size < 1)
		return TAMANHO_INVALIDO;

	vetor.subs[pos].data = malloc(sizeof(int) * size);

	if (!vetor.subs[pos].data)
		return SEM_ESPACO_DE_MEMORIA;

	return SUCESSO;

}


   // Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
   // Rertono (int)
   // SUCESSO - inserido com sucesso
   // SEM_ESPACO - não tem espaço
   // SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
   // POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
   // CONSTANTES
int inserirNumeroEmEstrutura(int pos, int val)
{
	int result;
	Node *node = NULL;

	--pos;

	if ((result = verificar_estrutura(pos)) != SUCESSO)
		return result;

	node = &vetor.subs[pos];

	if (node->current_size >= node->max_size)
		return SEM_ESPACO;

	node->data[node->current_size] = val;
	++node->current_size;


	return SUCESSO;
}

   // Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
   // ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
   // Obs. Esta é uma exclusão lógica
   //
   // Rertono (int)
   // SUCESSO - excluido com sucesso
   // ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
   // SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
   // POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
int excluirNumeroDoFinaldaEstrutura(int pos)
{
	int result;
	Node *node = NULL;

	--pos;

	if ((result = verificar_estrutura(pos)) != SUCESSO)
		return result;

	node = &vetor.subs[pos];

	if (!node->current_size)
   		return ESTRUTURA_AUXILIAR_VAZIA;

	--node->current_size;

	return SUCESSO;
}

   // Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
   // Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
   // ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
   // Obs. Esta é uma exclusão lógica
   // Rertono (int)
   // SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
   // ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
   // SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
   // NUMERO_INEXISTENTE - Número não existe
   // POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
int excluirNumeroEspecificoDeEstrutura(int pos, int val)
{
	// Valida se é possível excluir a sub-estrutura, encontra a posição do valor, reordena o vetor para que o valor excluído seja posto ao
	// final e decrementa o tamanho total do vetor (Exclusão lógica).
	int result;
	Node *node = NULL;

	--pos;

	if ((result = verificar_estrutura(pos)) != SUCESSO)
		return result;

	node = &vetor.subs[pos];

	if (!node->current_size)
   		return ESTRUTURA_AUXILIAR_VAZIA;

	int i = 0;

	for (; i < node->current_size; ++i) {
		if (node->data[i] == val)
			break;
	}

	++i;

	for (; i < node->current_size; ++i) {
		node->data[i-1] = node->data[i]; 	// Jogando os elementos seguintes pra trás para sobrepor o excluído. Último elemento fica livre
	}										// logicamente, não é necessário altera-lo.

	--node->current_size;

	return SUCESSO;

}

// se posição é um valor válido (entre 1 e 10)
int ehPosicaoValida(int pos) // Função inútil, mas ainda não sei se posso apagar
{
	if (pos < 0 || pos > 9)
		return POSICAO_INVALIDA;

	return SUCESSO;
}

   // Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
   // os números devem ser armazenados em vetorAux
   //
   // Retorno (int)
   // SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
   // SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
   // POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
int getDadosEstruturaAuxiliar(int pos, int buf[])
{
	int result;
	Node *node = NULL;

	--pos;

	if ((result = verificar_estrutura(pos)) != SUCESSO)
		return result;

	node = &vetor.subs[pos];

	for (int i = 0; i < node->current_size; ++i) {
		buf[i] = node->data[i];
	}

	int retorno = 0;
	return SUCESSO;
}

   // Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
   // os números devem ser armazenados em vetorAux
   // Rertono (int)
   // SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
   // SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
   // POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
int getDadosOrdenadosEstruturaAuxiliar(int pos, int buf[])
{
	int result;

	--pos;

	if ((result = getDadosEstruturaAuxiliar(pos, buf)) != SUCESSO)
		return result;

	for (int i = 1; i < vetor.subs[pos].current_size; ++i) {
		int tmp = buf[i];
		int j = i;

		while ( j > 0 && buf[j-1] > tmp) {
			buf[j] = buf[j-1];
			--j;
		}

		buf[j] = tmp;
	}

	return SUCESSO;
}

   // Objetivo: retorna os números de todas as estruturas auxiliares.
   // os números devem ser armazenados em vetorAux
   //
   // Rertono (int)
   // SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
   // TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
int getDadosDeTodasEstruturasAuxiliares(int buf[])
{
	Node *node;
	int *aux_buf = buf;

	for (int i = 0; i < 10; ++i) {
		node = &vetor.subs[i];

		for (int j = 0; node && j < node->current_size; ++j) {
			*buf = node->data[j];
			++buf;
		}
	}

	if (buf == aux_buf)
		return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

	return SUCESSO;
}

   // Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
   // os números devem ser armazenados em vetorAux
   //
   // Rertono (int)
   // SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
   // TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int buf[])
{
	if (getDadosDeTodasEstruturasAuxiliares(buf) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS)
		return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

	for (int i = 1; i < vetor.total_size; ++i) {
		int tmp = buf[i];
		int j = i;

		while ( j > 0 && buf[j-1] > tmp) {
			buf[j] = buf[j-1];
			--j;
		}

		buf[j] = tmp;
	}

	return SUCESSO;
}

   // Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
   // Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
   //
   // Rertono (int)
   // SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
   // SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
   // POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
   // NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
   // SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
int modificarTamanhoEstruturaAuxiliar(int pos, int new_size)
{
	int result;
	Node *node = NULL;

	--pos;

	if ((result = verificar_estrutura(pos)) != SUCESSO)
		return result;

	if (new_size > 0 || new_size > 10)
		return NOVO_TAMANHO_INVALIDO;

	node = &vetor.subs[pos];

	node = realloc(node, new_size * sizeof(int));

	if (!node)
		return SEM_ESPACO_DE_MEMORIA;

	return SUCESSO;
}

   // Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
   //
   // Retorno (int)
   // POSICAO_INVALIDA - posição inválida
   // SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
   // ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
   // Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
int getQuantidadeElementosEstruturaAuxiliar(int pos)
{
	int result;
	Node *node = NULL;

	--pos;

	if ((result = verificar_estrutura(pos)) != SUCESSO)
		return result;

	node = &vetor.subs[pos];

	if (!node->current_size)
   		return ESTRUTURA_AUXILIAR_VAZIA;

	return node->current_size;
}

   // Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
   //
   // Retorno (No*)
   // NULL, caso não tenha nenhum número nas listas
   // No*, ponteiro para o início da lista com cabeçote
No *montarListaEncadeadaComCabecote()
{

	return NULL;
}

   // Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
   // Retorno void
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

   // Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
   // O ponteiro inicio deve ficar com NULL.
   //
   // Retorno 
   // void.
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

   // Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
void inicializar()
{
}

   // Objetivo: finaliza o programa. deve ser chamado ao final do programa 
   // para poder liberar todos os espaços de memória das estruturas auxiliares.
void finalizar()
{
}

int verificar_estrutura(int pos)
{
	if (pos > 9 || pos < 0)
		return POSICAO_INVALIDA;
	
	if (!vetor.subs[pos].data)
		return SEM_ESTRUTURA_AUXILIAR;

	return SUCESSO;
}
