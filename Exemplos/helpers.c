#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "helpers.h"


int input_char() {
	struct termios old_t;
	struct termios new_t;
	tcgetattr(STDIN_FILENO, &old_t);	// Escreve o estado atual (flags) do terminal em old_t
	new_t = old_t;				// Copia old_t em new_t

	new_t.c_lflag &= ~(ICANON | ECHO);	// Fazendo and binário para desativar os bits de ICANON e ECHO em new_t
						// ICANON é o buffer de escrita e ECHO é o echo do input no terminal.
						
	tcsetattr(STDIN_FILENO, TCSANOW, &new_t); // Muda o estado do terminal para retirar o echo do input e pular o buffer
						  // de escrita, redirecionando o input direto para a stream
	int ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &old_t); // Reverte as mudanças para o estado do terminal lido em old_t

	return ch; // Retorna o caractére lido
}

void clean_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF); // Limpa o buffer até alcançar um enter, ou se achar o final da
						     // stream após ler alguns caractéres.
}

void    input_string(char *string, size_t size) {
	fgets(string, size, stdin);		// Recebe a string.
	string[strcspn(string, "\n")] = '\0';	// Trata o '\0'.
}

int procurar_vaga(Aluno *lista_alunos, size_t size) {
	for (int i = 0; i < size; ++i)
		if ( !(lista_alunos[i].matriculado) )
			return i;

	return -1;
}

void	inicializar_lista (Aluno *lista_alunos, size_t size) {
	for (int i = 0; i < size; ++i)
		lista_alunos[i].matriculado = 0;
}

int cadastrar(Aluno *lista_alunos, size_t size) {
	int vaga;

	if ((vaga = procurar_vaga(lista_alunos, size)) != -1) {
		lista_alunos[vaga].matriculado = 1;
		lista_alunos[vaga].matricula = 202600000 + vaga;

		puts("Digite o nome do aluno\n");
		input_string(lista_alunos[vaga].nome, 30);

		puts("\n\n");
		puts("Digite o cpf do aluno\n");
		scanf("%d", &lista_alunos[vaga].cpf);
		clean_buffer();

		puts("\n\n");
		puts("Digite a data de nascimento [DDMMAA] do aluno \n");
		scanf("%u", &lista_alunos[vaga].data_nascimento);
		lista_alunos[vaga].matricula += (lista_alunos[vaga].data_nascimento / 10000) * 1000;
		clean_buffer();

		puts("\n\n");
		puts("O aluno é semestralizado? (1 - Sim) (2 - Não): ");

		if (getchar() - '0')
			lista_alunos[vaga].semestralizado = 1;
		else
			lista_alunos[vaga].semestralizado = 0;

		clean_buffer();
	}
	else { return 1; } // Retornar 1 caso a lista esteja cheia

	puts("\n\n");
	puts("Aluno cadastrado com sucesso!\n");
	puts("\n\n");
	return 0; // Retornar 0 caso não haja nenhum erro
}
