// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include "trabalho1.h"
#include <stdio.h>
#include <stdlib.h>

// ######################################################### //
// ## Funções de utilidade que não precisam ir pro header ## //
// ######################################################### //

int charcmp(char letra1, char letra2, int case_s);
int converte_acentuada(int letra);
int valida_dia(struct data d);
int valida_mes(struct data d);
int valida_ano(struct data d);

// ######################################################### //

/*
## função utilizada para testes  ##
*/
int somar(int x, int y)
{
	int soma;
	soma = x + y;
	return soma;
}

/*
## função utilizada para testes  ##
*/
int fatorial(int x)
{
	int i, fat = 1;

	for (i = x; i > 1; i--)
		fat = fat * i;

	return fat;
}

int teste(int a)
{
	int val;
	if (a == 2)
		val = 3;
	else
		val = 4;

	return val;
}

/*
 * Q1 = validar data
 * @objetivo
 * Validar uma data
 * @entrada
 * uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e
 * aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
 * @saida
 * 0 -> se data inválida
 * 1 -> se data válida
 * @restrições
 * Não utilizar funções próprias de string (ex: strtok)
 * pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]) { return valida_data(get_data(data)); }

/*
 * Q2 = diferença entre duas datas
 * @objetivo
 * Calcular a diferença em anos, meses e dias entre duas datas
 * @entrada
 * uma string datainicial, uma string datafinal.
 * @saida
 * Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
 * 1 -> cálculo de diferença realizado com sucesso
 * 2 -> datainicial inválida
 * 3 -> datafinal inválida
 * 4 -> datainicial > datafinal
 * Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser
 * preenchidos com os valores correspondentes.
 */
// typedef struct Qtd
// {
//     int qtdDias;
//     int qtdMeses;
//     int qtdAnos;
//     int retorno;
//
// } DMA;
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
	DiasMesesAnos result = {0};
	if (*datafinal)
		return result;
	else if (*datainicial)
		return result;
	return result;
}

/*
 * Q3 = encontrar caracter em texto
 * @objetivo
 * Pesquisar quantas vezes um determinado caracter ocorre em um texto
 * @entrada
 * uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou
 * não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
 * Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e
 * minúsculos.
 * @saida
 * Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive) { return acha_letra(texto, c, isCaseSensitive); }

/*
 * Q4 = encontrar palavra em texto
 * @objetivo
 * Pesquisar todas as ocorrências de uma palavra em um texto
 * @entrada
 * uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que
 * irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base
 * (texto).
 * @saida
 * Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
 * O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo,
 * se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do
 * texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas
 * ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim
 * consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como
 * há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
 * posicoes[0] = 13; posicoes[1] = 16; Observe que o índice da posição no texto deve começar ser
 * contado a partir de 1. O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
	return acha_palavra(strTexto, strBusca, posicoes);
}

/*
	Q5 = inverte número
	@objetivo
	Inverter número inteiro
	@entrada
	uma int num.
	@saida
	Número invertido
*/
int q5(int num) { return inverte_numero(num); }

/*
 * Q6 = ocorrência de um número em outro
 * @objetivo
 * Verificar quantidade de vezes da ocorrência de um número em outro
 * @entrada
 * Um número base (numerobase) e um número de busca (numerobusca).
 * @saida
 * Quantidade de vezes que número de busca ocorre em número base
 */
int q6(int numerobase, int numerobusca) { return acha_numero(numerobase, numerobusca); }

/*
 * Q7 = jogo busca palavras
 * @objetivo
 * Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos
 * possíves
 * @entrada
 * Uma matriz de caracteres e uma string de busca (palavra).
 * @saida
 * 1 se achou 0 se não achou
 */
int q7(char matriz[8][10], char palavra[5])
{
	if(busca_horizontal(matriz, palavra))
		return 1;
	if (busca_diagonal(matriz, palavra))
		return 1;
	return 0;
}

// ####################
// ## Minhas funções ##
// ####################

int valida_data(struct data data)
{
	if (!valida_dia(data))
		return 0;
	if (!valida_mes(data))
		return 0;
	if (!valida_ano(data))
		return 0;

	return 1;
}

struct data get_data(char *string)
{
	struct data buf_data = {0};

	uint32_t *dma[3] = {&buf_data.dia, &buf_data.mes, &buf_data.ano};
	char *ptr = string;
	size_t i = 0;

	while (*ptr && i < 3) {
		while (*ptr == ' ') {
			++ptr;
		}

		*dma[i] = strtou(ptr, &ptr);
		++ptr; // Incrementa o ponteiro para sair da '/'
		++i;
	}

	switch (buf_data.mes) {
	case 11:
	case 8:
	case 6:
	case 4:
		buf_data.mes_31_dias = 0;
		break;
	default:
		buf_data.mes_31_dias = 1;
		break;
	}

	if ((!(buf_data.ano % 4) && (buf_data.ano % 100)) || !(buf_data.ano % 4))
		buf_data.bissexto = 1;

	return buf_data;
}

int isnumber(char a)
{
	if (a >= '0' && a <= '9')
		return 1;
	return 0;
}

uint32_t strtou(char *ptr, char **ptr2)
{
	int numero = 0;

	while (*ptr) {
		if (isnumber(*ptr))
			numero = (numero * 10) + (*ptr - '0');
		else
			break;

		++ptr;
	}

	*ptr2 = ptr;
	return numero;
}

int acha_numero(int num, int val)
{
	int count = 0, x = 10;

	for (int tmp = val; (tmp / 10) > 0; tmp /= 10, x *= 10)
		;

	while (num > 0) {
		if ((num % x) == val)
			++count;

		num /= 10;
	}

	return count;
}

int inverte_numero(int num)
{
	int resultado = 0;
	while (num > 0) {
		resultado = (resultado * 10) + num % 10;
		num /= 10;
	}

	return resultado;
}

int acha_letra(char *string, char letra, int case_s)
{
	int quantity = 0;

	while (*string) {
		if (*string == -61) {
			++string;
		}

		if (charcmp(letra, *string, case_s)) {
			++quantity;
			++string;
		}

		++string;
	}

	return quantity;
}

int valida_dia(struct data d)
{
	if (d.dia <= 0)
		return 0;
	if (d.dia > 31)
		return 0;
	if (d.dia == 31 && !d.mes_31_dias)
		return 0;
	if (d.mes == 2 && d.dia > 29)
		return 0;
	if (d.mes == 2 && !d.bissexto && d.dia == 29)
		return 0;

	return 1;
}

int valida_mes(struct data d)
{
	if (d.mes <= 0)
		return 0;
	if (d.mes > 12)
		return 0;

	return 1;
}

int valida_ano(struct data d)
{
	if (d.ano <= 0)
		return 0;
	return 1;
}

int converte_acentuada(int letra)
{
	int acentuados[2][10] = {{-95, -87, -83, -77, -70, -127, -119, -115, -109, -102},
				 {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}};

	for (int j = 0; j < 9; ++j) {
		if (letra == acentuados[0][j])
			return acentuados[1][j];
	}

	return 0;
}

int charcmp(char letra1, char letra2, int case_s)
{
	case_s = !case_s ? 32 : 0;

	if (letra2 < 0)
		letra2 = converte_acentuada(letra2);

	if (letra1 == letra2 || letra1 == (letra2 + case_s) || letra1 == (letra2 - case_s))
		return 1;

	return 0;
}

int busca_horizontal(char matriz[8][10], char *palavra)
{
	int count = 0;
	for (int i = 7; i >= 0; --i) {
		int j = 9, x = 0;
		while (1) {
			if (palavra[x] == '\0') {
				++count;
				x = 0;
				--j;
			}

			if ((j - x) < 0) {
				break;
			}

			if (palavra[x] == matriz[i][j - x]) {
				++x;
				continue;
			}

			x = 0;
			--j;
		}
	}

	for (int i = 0; i < 8; ++i) {
		int j = 0, x = 0;
		while (1) {
			if (palavra[x] == '\0') {
				++count;
				x = 0;
				++j;
			}

			if (matriz[i][j + x] == '\0') {
				break;
			}

			if (palavra[x] == matriz[i][j + x]) {
				++x;
				continue;
			}

			x = 0;
			++j;
		}
	}

	return count;
}

int busca_diagonal(char matriz[8][10], char *palavra)
{
	int count = 0;
	for (int i = 7; i >= 0; --i) {
		int j = 8, x = 0;
		while (1) {
			if (palavra[x] == '\0') {
				++count;
				--j;
				x = 0;
			}

			if ((i - x) < 0 || (j - x) < 0) {
				break;
			}

			if (palavra[x] == matriz[i-x][j-x]) {
				++x;
				continue;
			}

			x = 0;
			--j;
		}
	}

	for (int i = 0; i < 8; ++i) {
		int j = 0, x = 0;
		while (1) {
			if (palavra[x] == '\0') {
				++count;
				--j;
				x = 0;
			}

			if ((i + x) > 7 || (j + x) > 9) {
				break;
			}

			if (palavra[x] == matriz[i+x][j+x]) {
				++x;
				continue;
			}

			x = 0;
			++j;
		}
	}

	return count;
}

int acha_palavra(char *texto, char *palavra, int posicoes[30])
{
	int count = 0;

	for (int i = 0, j = 0, pos = 0, poscount = 0; texto[j] != '\0';) {

		if (texto[j + i] == palavra[i] && palavra[i] != '\0') {
			if (texto[j+i] > 0)
				++pos;
			++i;
			continue;
		}

		if (palavra[i] == '\0') {
			posicoes[poscount] = pos - i + 1;
			posicoes[poscount + 1] = pos;
			printf("%d, %d\n", posicoes[poscount], posicoes[poscount + 1]);
			poscount += 2;
			++count;
		}

		++j;
		pos = j;
		i = 0;
	}

	return count;
}

