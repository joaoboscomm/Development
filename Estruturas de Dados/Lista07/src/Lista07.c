/*
 ============================================================================
 Name        : Lista07.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

void menu();
int digitarNumero(char *frase);

int main(void) {
	setbuf(stdout, NULL);
	menu();
	return 0;
}

void menu(){
	int i,
		op,
		controle = -1;

	memoria *operacoes = (memoria*) malloc (TAM * sizeof(memoria));

	do{
		printf("\n1 - Somar dois valores"
				"\n2 - Subtrair dois valores"
				"\n3 - Multiplicar dois valores"
				"\n4 - Dividir dois valores"
				"\n5 - Calcular fatorial"
				"\n6 - Imprimir mem�ria de c�lculos"
				"\n7 - Finalizar"
				"\nDigite sua op��o: ");
		fflush(stdin);
		scanf("%d", &op);

		switch (op) {
			case 1:
				controle++;
				operacoes[controle].termo1 = digitarNumero("Digite o primeiro n�mero: ");
				operacoes[controle].termo2 = digitarNumero("Digite o segundo n�mero: ");
				operacoes[controle].tipo = '+';
				operacoes[controle].resultado = calc.soma(operacoes[controle].termo1,
														  operacoes[controle].termo2);
				printf("\nO resultado da soma � %.0lf", operacoes[controle].resultado);
				break;
			case 2:
				controle++;
				operacoes[controle].termo1 = digitarNumero("Digite o primeiro n�mero: ");
				operacoes[controle].termo2 = digitarNumero("Digite o segundo n�mero: ");
				operacoes[controle].tipo = '-';
				operacoes[controle].resultado = calc.subtracao(operacoes[controle].termo1,
														       operacoes[controle].termo2);
				printf("\nO resultado da subtra��o � %.0lf", operacoes[controle].resultado);
				break;
			case 3:
				controle++;
				operacoes[controle].termo1 = digitarNumero("Digite o primeiro n�mero: ");
				operacoes[controle].termo2 = digitarNumero("Digite o segundo n�mero: ");
				operacoes[controle].tipo = '*';
				operacoes[controle].resultado = calc.multiplica(operacoes[controle].termo1,
														        operacoes[controle].termo2);
				printf("\nO resultado da multiplica��o � %.0lf", operacoes[controle].resultado);
				break;
			case 4:
				controle++;
				operacoes[controle].termo1 = digitarNumero("Digite o primeiro n�mero: ");
				operacoes[controle].termo2 = digitarNumero("Digite o segundo n�mero: ");
				while (operacoes[controle].termo2 == 0) {
					printf("\nN�o existe divis�o por zero.");
					operacoes[controle].termo2 = digitarNumero("Digite o segundo n�mero: ");
				}
				operacoes[controle].tipo = '/';
				operacoes[controle].resultado = calc.divisao(operacoes[controle].termo1,
														        operacoes[controle].termo2);
				printf("\nO resultado da divisao � %.2lf", operacoes[controle].resultado);
				break;
			case 5:
				controle++;
				operacoes[controle].termo1 = digitarNumero("Digite o primeiro n�mero: ");
				while (operacoes[controle].termo1 < 0) {
					printf("\nN�o existe fatorial de n�meros negativos.");
					operacoes[controle].termo1 = digitarNumero("Digite o segundo n�mero: ");
				}
				operacoes[controle].tipo = '!';
				operacoes[controle].resultado = calc.fatorial(operacoes[controle].termo1);
				printf("\nO resultado do fatorial � %.0lf", operacoes[controle].resultado);
				break;
			case 6:
				for (i = 0; i <= controle; i++) {
					if (operacoes[i].tipo != '!') {
						printf("\n%d %c %d = %.2lf", operacoes[i].termo1,
													 operacoes[i].tipo,
													 operacoes[i].termo2,
													 operacoes[i].resultado);
					} else {
						printf("\n%d %c = %.0lf", operacoes[i].termo1,
													 operacoes[i].tipo,
													 operacoes[i].resultado);

					}
				}
				break;
			case 7:
				printf("\nPrograma finalizado.");
				break;
			default:
				printf("\nValor inv�lido");
				break;
		}

		if (controle == 4) {
			break;
		}
	} while (op != 7);
}

int digitarNumero(char *frase){
	int numero;
	printf("\n%s", frase);
	fflush(stdin);
	scanf("%d", &numero);
	return numero;
}


