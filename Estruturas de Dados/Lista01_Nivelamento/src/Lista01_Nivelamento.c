/*
 ============================================================================
 Name        : Lista01_Nivelamento.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	setbuf(stdout, NULL);

	//Declara��o de vari�veis
	char 	op;
	int 	termos,
			numero;
	double	resultado;


	//Loop para toda a l�gica
	for(;;) {
		do{
			printf("\nA - Calcular a s�rie A"
					"\nB - Calcular a s�rie B"
					"\nC - Calcular a s�rie C"
					"\nD - Finalizar digita��o"
					"\nDigite sua op��o: ");
			fflush(stdin);
			scanf("%c", &op);

			if (op < 'A' || op > 'D') {
				printf("\nInv�lido. Digite novamente.");
			}
		} while (op < 'A' || op > 'D'); //Validar para ser de A at� D

		if (op == 'D'){ //Finalizar
			printf("\nPrograma finalizado.");
			break;
		} else {
			//Solicitar termos
			printf("\nDigite a quantidade de termos a ser calculada: ");
			fflush(stdin);
			scanf("%d", &termos);

			//Validar para s� receber positivos
			while (termos <= 0) {
				printf("\nValor inv�lido. Digite a quantidade de termos a ser calculada: ");
				fflush(stdin);
				scanf("%d", &termos);
			}

			//Inicializa��o de vari�veis
			resultado = 0;
			numero = 1;

			//Calcular as s�ries
			switch (op) {
			case 'A' : //S�rie A
						while (termos > 0) {
							resultado += (double) (numero + (numero - 1)) / pow(numero, 2);
							numero++;
							termos--;
						}


						break;

			case 'B': //S�rie B
						do{
							resultado += (double) pow(numero, 3) / pow(10, numero - 1);
							numero++;
							termos--;
						} while (termos > 0);

						break;
			case 'C': //S�rie C
						for(; termos > 0; termos--){
							resultado += (double) numero / (3 * (numero * 2));
							numero++;
						}
						break;
			} //Finaliza o switch

			//Exibir resultado final
			printf("\nO resultado � %.2lf\n", resultado);
		} //Finaliza o else
	} //Finaliza o for

	return 0;
}
