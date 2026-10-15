// Definindo o tipo size_t
#include <stddef.h>
#include <stdint.h>

typedef struct {
	char nome[30];
	int matricula;
	unsigned int cpf;
	unsigned int data_nascimento; // DDMMAA
	uint8_t matriculado	:1;
	uint8_t semestralizado	:1;
} Aluno;

typedef struct {
	char nome[30];
	char codigo[6];
	Aluno *matriculados[3];
} Disciplina;

// Permite o input de um caractére sem buffer de escrita (Aperta a tecla e o terminal lê) e sem echo (Não é desenhado na
// tela, mas acho que vou devolver o echo).
int input_char(); 

// Usar após funções como o getchar() e scanf() que deixam um '\n' pra trás, arriscando afetar outras funções de input.
void clean_buffer();

// Permite o input de uma string e substitui o caractére '\n' lido pelo fgets() por um '\0'.
void input_string(char *string, size_t size);

// Procura algum aluno.matriculado == 0 na lista de alunos e devolve para o código qual sua posição em lista_alunos.
int procurar_vaga(Aluno *lista_alunos, size_t size);

// Inicializa a lista modificando o valor de aluno.matriculado para cada aluno em lista_alunos.
void inicializar_lista (Aluno *lista_alunos, size_t size);

// Realiza o cadastro de um aluno na primeira posição vaga encontrada (Possível mudança para permitir checagem bilateral
// por lista_alunos procurando alguma vaga disponivel).
int cadastrar(Aluno *lista_alunos, size_t size);
