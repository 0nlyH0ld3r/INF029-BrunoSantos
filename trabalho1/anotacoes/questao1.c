#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct data {
	uint32_t dia;
	uint32_t mes;
	uint32_t ano;
	uint8_t bissexto;
	uint8_t mes_31_dias;
};

int isnumber(char a);
unsigned int strtou(char *ptr, char **ptr2);
struct data get_data(char *string);
static inline int valida_mes(struct data d);
static inline int valida_dia(struct data d);
static inline int valida_ano(struct data d);

int valida_data(struct data data);

// Adicionar no arquivo q1.c essa função.
// Ela vai ser adicionada ao return, então retornar 0 ou 1 somente.
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

	if ((!(buf_data.mes % 4) && (buf_data.mes % 100)) || !(buf_data.mes % 4))
		buf_data.bissexto = 1;

	return buf_data;
}

static inline int valida_dia(struct data d)
{
	if (d.dia == 0)
		return 0;
	if (d.dia > 31)
		return 0;
	if (d.dia > 29 && d.mes == 2)
		return 0;
	if (d.dia == 31 && !d.mes_31_dias)
		return 0;
	if (d.dia == 29 && d.mes == 2 && !d.bissexto)
		return 0;

	return 1;
}

static inline int valida_mes(struct data d)
{
	if (d.mes == 0)
		return 0;
	if (d.mes > 12)
		return 0;

	return 1;
}

static inline int valida_ano(struct data d)
{
	if (d.ano == 0)
		return 0;
	return 1;
}

int isnumber(char a)
{
	if (a >= '0' && a <= '9')
		return 1;
	return 0;
}

unsigned int strtou(char *ptr, char **ptr2)
{
	int numero = 0;
	for (int x = 1; *ptr; x *= 10) {
		if (isnumber(*ptr))
			numero += (numero * x) + *ptr;
		else
			break;

		++ptr;
	}

	*ptr2 = ptr;
	return numero;
}
