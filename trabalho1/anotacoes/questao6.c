int acha_numero(int num, int val) {
	int count = 0, x = 10;
	
	for (int tmp = val; (tmp / 10) > 0; tmp /= 10, x *= 10);

	while (num > 0) {
		if ((num % x) == val)
			++count;

		num /= 10;
	}

	return count;
}
