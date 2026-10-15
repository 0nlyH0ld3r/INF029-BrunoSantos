// static inline int converte_acentuada(int letra)
// {
// 	int acentuados[2][10] = {
// 		{-95, -87, -83, -77, -70, -127, -119, -115, -109, -102},
// 		{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
// 	};
//
// 	for (int j = 0; j < 9; ++j) {
// 		if (letra == acentuados[0][j])
// 			return acentuados[1][j];
// 	}
//
// 	return 0;
// }
//
// static inline int charcmp(char letra1, char letra2, int case_s)
// {
// 	if (case_s)
// 		case_s = 32;
// 	if (letra2 < 0)
// 		letra2 = converte_acentuada(letra2);
//
// 	if (letra1 == letra2 || letra2 + case_s)
// 		return 1;
//
// 	return 0;
// }
//
// int acha_letra(char *string, char letra, int case_s) 
// {
// 	int quantity = 0;
//
// 	while (*string) {
// 		if (*string == -61) {
// 			++string;
// 		}
//
// 		if ( charcmp(letra, *string, case_s) ) {
// 			++quantity;
// 			++string;
// 		}
//
// 		++string;
// 	}
//
// 	return quantity;
// }

// TODO:
int q4(char *string, char*sub_string, int posicoes[30])
{
	int quantity = 0;
	for (int i = 0; string[i]; ++i) {
		int j = 0;

		if (string[i] == sub_string[j]) {
			++j;

			while (string[i + j] && string[i + j] == sub_string[j]) {
				if (sub_string[j]) {
					++j;
					continue;
				}

				++quantity;
			}
		}
	}

	return quantity;
}
