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
// Última atualização: 07/05/2021

// #################################################
#ifndef TRABALHO1_H
#define TRABALHO1_H

#include <stdint.h>

struct data {
	uint32_t dia;
	uint32_t mes;
	uint32_t ano;
	uint8_t bissexto;
	uint8_t mes_31_dias;
};

typedef struct Qtd
{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;

} DiasMesesAnos;

/*
 *
 * FUNÇÕES DE Q1
 *
 */

// Função que verifica se o caracter é um número
//
// Recebe um caracter
//
// Retorna um inteiro, 0 ou 1 (falso ou verdadeiro)
int isnumber(char a);

// → string to unsigned int
//
// Função que coleta números inteiros sem sinais de uma string.
//
// Recebe um ponteiro char (string) e um ponteiro pra ponteiros char (marcador de posição na string).
//
// Caso encontre algum caracter não numérico, irá interromper a busca, retornar um valor e **ptr2 apontará
// para esse caractere.
//
// Ex:  123a <- *ptr2 == 'a', retorna 123
//
// Retorna um inteiro sem sinal (exclusivamente positivo).
unsigned int strtou(char *ptr, char **ptr2);

// Função transforma datas (strings) em uma struct data { .dia, .mes, .ano, ...}
// 
// @param char*
//
// Recebe uma string 
//
// @return struct data
//
// Retorna uma struct data, que contém a data coletada, flags se o ano é bissexto e se o mês
// tem 31 dias
struct data get_data(char *string);

// Função que valida uma data (struct data).
//
// @return struct data
//
// Recebe um objeto struct data
//
// @return int <- bool
//
// Retorna um inteiro, 0 ou 1 (falso ou verdadeiro)
int valida_data(struct data data);

// Encontra um número dentro de outro.
//
// @param int, int
//
// Recebe um número onde deve pesquisar (num) e um número para pesquisar (val).
//
// @return int
//
// Retorna a contagem de vezes que val foi encontrado em num.
int acha_numero(int num, int val);

// Inverte um número
//
// @param int
//
// Recebe um número para reverter
//
// @return int
//
// Retorna o número ao contrário (Ex: 123 -> 321)
int inverte_numero(int num);

int acha_palavra(char *texto, char *palavra, int posicoes[30]);

int acha_letra(char *string, char letra, int case_s);

int busca_diagonal(char matriz[8][10], char* palavra);
int busca_horizontal(char matriz[8][10], char *palavra);

int somar(int x, int y); //função utilizada para testes
int fatorial(int x); //função utilizada para testes
int q1(char data[]);
DiasMesesAnos q2(char datainicial[], char datafinal[]);
int q3(char *texto, char c, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);
int q7(char matriz[8][10], char palavra[5]);

#endif  // MAIN_H
