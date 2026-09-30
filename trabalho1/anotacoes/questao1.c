#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

struct data {
	uint32_t dia;
	uint32_t mes;
	uint32_t ano;
	uint8_t bissexto;
	uint8_t mes_31_dias;
};

static inline struct data fetch_data(char *string);
static inline void mes_31_dias(struct data *d);
static inline void ano_bissexto(struct data *d);
static inline int valida_mes(struct data d);
static inline int valida_dia(struct data d);
static inline int valida_ano(struct data d);

int valida_data(char *string_data);

int main(int argc, char **argv)
{
	if (argc < 2)
		exit(1);

	return valida_data(argv[2]);
}

// Adicionar no arquivo q1.c essa função.
// Ela vai ser adicionada ao return, então retornar 0 ou 1 somente.
int valida_data(char *string_data)
{
	struct data d = fetch_data(string_data);

	if (!valida_dia(d)) 
		return 0;
	if (!valida_mes(d)) 
		return 0;
	if (!valida_ano(d)) 
		return 0;

	return 1;
	
}

static inline struct data fetch_data(char *string)
{
	struct data buf_data = {0};

	uint32_t *dma[3] = {&buf_data.dia, &buf_data.mes, &buf_data.ano};
	char *ptr = string;
	size_t i = 0;

	while (*ptr && i < 3) {
		while (*ptr == ' ') {
			++ptr;
		}

		*dma[i] = strtol(ptr, &ptr, 10);
		++ptr; // Incrementa o ponteiro para sair da '/'
		++i;
	}

	mes_31_dias(&buf_data); // Verifica se deveria ter 31 dias ou não.
	ano_bissexto(&buf_data);

	return buf_data;
}

static inline void mes_31_dias(struct data *d)
{
	switch (d->mes) {
	case 11:
	case 8:
	case 6:
	case 4:
		d->mes_31_dias = 0;
		break;
	default:
		d->mes_31_dias = 1;
		break;
	}
}

static inline void ano_bissexto(struct data *d)
{
	// Se (V e F) ou V <- Se (não tem resto e tem resto) ou não tem resto
	if ((!(d->mes % 4) && (d->mes % 100)) || !(d->mes % 4))
		d->bissexto = 1;
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

