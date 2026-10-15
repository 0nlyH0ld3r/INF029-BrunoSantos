int inverte_numero(int num) {
	int resultado = 0;
	while (num > 0) {
		resultado = (resultado * 10) + num % 10;
		num /= 10;
	}

	return resultado;
}
