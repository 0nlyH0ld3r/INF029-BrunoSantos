#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[30];
	int ano;
	int preco;
} Celular;

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

	initialize_vector(lista_celulares, tamanho);

	while(!sair) {
		puts("Digite uma opção: \n");
		puts("0: Sair\n");
		puts("1: Inserir\n");
		puts("2: Listar\n");
		puts("3: Atualizar\n");
		puts("4: Deletar\n");

		int opcao;
		int x;
		scanf("%d", &opcao);
		clean_buffer();

		switch(opcao) {
		case 0: 
			sair = 1;
			break;
		case 1: 
			switch(inserir(lista_celulares, tamanho)) {
			case 0:
				puts("Cadastro bem sucedido!\n");
				break;
			case 1:
				puts("Não há espaço para realizar o cadastro!\n");
				break;
			}
			break;
		case 2: 
			listar(lista_celulares, tamanho);
			break;
		case 3: 
			puts("Qual celular deseja atualizar: ");
			scanf("%d", &x);
			clean_buffer();
			atualizar(&lista_celulares[x]);
			break;
		case 4: 
			puts("Qual celular deseja deletar: ");
			scanf("%d", &x);
			clean_buffer();
			deletar(&lista_celulares[x]);
			break;
		}
	}
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
		puts("\n\nDigite o nome do novo celular\n");
		input_string(lista_celulares[slot].nome, 30);

		puts("Digite o ano do novo celular\n");
		scanf("%d", &lista_celulares[slot].ano);
		clean_buffer();

		puts("Digite o preço do novo celular\n");
		scanf("%d", &lista_celulares[slot].preco);
		clean_buffer();
	}
	else { return 1; } // Retornar 1 caso a lista esteja cheia
	
	puts("Celular cadastrado com sucesso!\n");
	return 0; // Retornar 0 caso não haja nenhum erro
}

void listar(Celular lista_celulares[], size_t size) {
	for (int i = 0; i < size; ++i) {
		if (lista_celulares[i].ano == -1) 
			continue;
		else
			printf("%d - Nome: %s\nAno: %d\nPreço: %d\n\n", 
				i, lista_celulares[i].nome, lista_celulares[i].ano, lista_celulares[i].preco);
	}
	puts("\n");
}

void	atualizar(Celular *celular) {
		puts("\n\nDigite o novo nome do celular\n");
		input_string(celular->nome, 30);
		clean_buffer();

		puts("Digite o novo ano do celular\n");
		scanf("%d", &celular->ano);
		clean_buffer();

		puts("Digite o novo preço do celular\n");
		scanf("%d", &celular->preco);
		clean_buffer();

		printf("Atualização concluída!\n\n");
}

void deletar(Celular *celular) {
	celular->nome[0] = '\0';
	celular->ano = -1;
	celular->preco = -1;
}


