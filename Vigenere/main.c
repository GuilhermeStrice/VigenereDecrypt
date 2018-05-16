#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **numeros;

char *intToString(int i)
{
	switch (i)
	{
	case 1:return "ONE\0";
	case 2:return "TWO\0";
	case 3:return "THREE\0";
	case 4:return "FOUR\0";
	case 5:return "FIVE\0";
	case 6:return "SIX\0";
	case 7:return "SEVEN\0";
	case 8:return "EIGHT\0";
	case 9:return "NINE\0";
	}
}

int main(int argc, char **argv) 
{
	numeros = malloc(729 * sizeof(char*));

	int contagem = 0;
	for (int i = 1; i <= 9; i++)
	{
		for (int k = 1; k <= 9; k++)
		{
			for (int j = 1; j <= 9; j++)
			{
				char *temp = intToString(i);
				char *temp2 = intToString(k);
				char *temp3 = intToString(j);
				numeros[contagem] = malloc(sizeof(char*));
				memcpy(numeros[contagem], temp, strlen(temp));
				memcpy(numeros[contagem] + strlen(temp), temp2, strlen(temp2));
				memcpy(numeros[contagem] + strlen(temp) + strlen(temp2), temp3, strlen(temp3));
				numeros[contagem][strlen(temp) + strlen(temp2) + strlen(temp3)] = '\0';
				contagem++;
			}
		}
	}

	char *input = malloc(sizeof(char*));

	fgets(input, 10000, stdin);

	char *cifra = malloc(sizeof(char*));
	int tamanho = 0;
	for (int i = 0; input[i] != '\n'; i++)
	{
		cifra[i] = input[i];
		cifra[i] = (char)toupper(cifra[i]);
		++tamanho;
	}

	cifra[tamanho] = '\0';
	
	for (int i = 728; i >= 0; i--)
	{
		char *numero = numeros[i];

		if (strlen(numero) != tamanho)
			continue;

		char *desencriptado = malloc(sizeof(char*));
		char *chave = malloc(sizeof(char*));

		int flag = 0;
		for (int k = 0; k < tamanho; k++)
		{
			for (int j = 65; j <= 90; j++)
			{
				char char_desencriptado = ((cifra[k] - j + 26) % 26) + 65;
				if (char_desencriptado == numero[k])
				{
					desencriptado[k] = char_desencriptado;
					chave[k] = j;
					flag = 1;
					break;
				}
				else flag = 0;
			}
		}

		if (flag)
		{
			desencriptado[tamanho] = '\0';
			chave[tamanho] = '\0';
			printf("%s->%s\n", chave, desencriptado);
		}
	}

	printf("Press Any Key to Continue\n");
	getchar();
	return 0;
}