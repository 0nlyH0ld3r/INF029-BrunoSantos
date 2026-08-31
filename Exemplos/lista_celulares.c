#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

typedef struct {
	char nome[30];
	int ano;
	int preco;
} Celular;

int	input_char(); 
void	clean_buffer();
void	initialize_vector (Celular *lista_celulares, size_t size);
void    input_string(char *string, size_t size);
int	search_empty(Celular *lista_celulares, size_t size);

int	inserir(Celular *lista_celulares, size_t tam);
void	listar(Celular lista_celulares[], size_t size);
void	atualizar(Celular *celular);
void	deletar(Celular *celular);

int main() {
	int tamanho = 3;
	Celular lista_celulares[tamanho];
	int sair = 0;

	system("clear");
	initialize_vector(lista_celulares, tamanho);

	do {
		puts("Digite uma opção: \n");
		puts("0: Sair\n");
		puts("1: Inserir\n");
		puts("2: Listar\n");
		puts("3: Atualizar\n");
		puts("4: Deletar\n");

		// int opcao;
		int x;
		// scanf("%d", &opcao);

		switch(input_char() - '0') {
			case 0: 
				return 0;
				break;

			case 1: 
				system("clear");
				switch(inserir(lista_celulares, tamanho)) {
					case 0:
						puts("Cadastro bem sucedido!\n\n");
						break;
					case 1:
						puts("Não há espaço para realizar o cadastro!\n\n");
						break;
				}
				break;

			case 2: 
				system("clear");
				listar(lista_celulares, tamanho);
				break;

			case 3: 
				system("clear");
				puts("Qual celular deseja atualizar: ");
				scanf("%d", &x);
				clean_buffer();
				atualizar(&lista_celulares[x]);
				break;

			case 4: 
				system("clear");
				puts("Digite o número do celular deseja deletar: "); // Criar atributo ID_Produto
				scanf("%d", &x);
				clean_buffer();
				deletar(&lista_celulares[x]);
				break;
			default:
				puts("Digite uma opção válida!\n");
				break;
		}

		puts("Deseja sair do programa? (0 - Sair): ");

		if (input_char() == '0')
			sair = 1;

		system("clear");

	} while(!sair);
}

int input_char() {
	struct termios old_t;
	struct termios new_t;
	tcgetattr(STDIN_FILENO, &old_t);
	new_t = old_t;
	new_t.c_lflag &= ~(ICANON | ECHO);

	tcsetattr(STDIN_FILENO, TCSANOW, &new_t); // Muda o estado do terminal para retira o echo do input e pular o buffer
						  // de escrita, redirecionando o input direto para a stream
	int ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &old_t); // Reverte as mudanças

	return ch;
}

void clean_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF); // Limpa o buffer até o próximo Enter
}

void	initialize_vector (Celular *lista_celulares, size_t size) {
	for (int i = 0; i < size; ++i) {
		lista_celulares[i].nome[0] = '\0';
		lista_celulares[i].ano = -1;
		lista_celulares[i].preco = -1;
	}
}

void    input_string(char *string, size_t size) {
	fgets(string, size, stdin);
	string[strcspn(string, "\n")] = '\0';
}

int search_empty(Celular *lista_celulares, size_t size) {
	for (int i = 0; i < size; ++i)
		if (lista_celulares[i].ano == -1)
			return i;

	return -1;
}

int inserir(Celular *lista_celulares, size_t size) {
	int slot;

	if ((slot = search_empty(lista_celulares, size)) != -1) {
		puts("Digite o nome do novo celular\n");
		input_string(lista_celulares[slot].nome, 30);

		puts("\n\n");
		puts("Digite o ano do novo celular\n");
		scanf("%d", &lista_celulares[slot].ano);
		clean_buffer();

		puts("\n\n");
		puts("Digite o preço do novo celular\n");
		scanf("%d", &lista_celulares[slot].preco);
		clean_buffer();
	}
	else { return 1; } // Retornar 1 caso a lista esteja cheia

	puts("\n\n");
	puts("Celular cadastrado com sucesso!\n");
	return 0; // Retornar 0 caso não haja nenhum erro
}

void listar(Celular lista_celulares[], size_t size) {
	for (int i = 0; i < size; ++i) {
		if (lista_celulares[i].ano == -1) 
			continue;
		else
			printf("%d - NOME: %s\n\nAno: %d\nPreço: %d\n\n", i, lista_celulares[i].nome, lista_celulares[i].ano, lista_celulares[i].preco);
	}
	puts("\n");
}

void atualizar(Celular *celular) {
	int op;

	clean_buffer();
	puts("Deseja atualizar o nome? (s - sim) (n - não): ");

	if ((op = input_char()) == 's' || op == 'S') {
		puts("\n\n");
		puts("Digite o novo nome do celular\n");
		input_string(celular->nome, 30);
	}


	puts("\nDeseja atualizar o ano? (s - sim) (n - não): ");

	if ((op = input_char()) == 's' || op == 'S') {
		puts("\n\n");
		puts("Digite o novo ano do celular\n");
		scanf("%d", &celular->ano);
		clean_buffer();
	}


	puts("\nDeseja atualizar o preço? (s - sim) (n - não): ");

	if ((op = input_char()) == 's' || op == 'S') {
		puts("\n\n");
		puts("Digite o novo preço do celular\n");
		scanf("%d", &celular->preco);
		clean_buffer();
	}

	printf("Atualização concluída!\n\n");
}

void deletar(Celular *celular) {
	celular->nome[0] = '\0';
	celular->ano = -1;
	celular->preco = -1;
}


