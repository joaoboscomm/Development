/*
 ============================================================================
 Name        : Aula01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {
	setbuf(stdout, NULL); //Limpar o buffer de v�deo

	int x;

	double y;

	x = 45;
	y = x++;

	//imprimir s� texto
	printf("Testando 1 2 3\n");

	//imprimir s� vari�vel
	printf("%d", x);

	//imprimir texto e vari�vel
	printf("\nA vari�vel x possui valor = %d e y = %.2f", x, y);

	//Inclus�o de valor em x
	printf("\nDigite o valor de x: ");
	scanf("%d", &x);

	//Operador tern�rio
	if (x > 15) {
		y = 19;
	} else {
		y = 12;
	}

	y = x > 15 ? 19 : 12;  //Operador tern�rio para o if anterior
	printf("\nO valor de y � %lf", y);

	if (x % 2 == 0) {
		printf("\nPar");
	} else {
		printf("\n�mpar");
	}

	x % 2 == 0 ? printf("\nPar") : printf("\n�mpar"); //Operador tern�rio para o if anterior



	char op;
	printf("\nOp��o: ");
	fflush(stdin); //Limpar o ponteiro para a digita��o
	scanf("%c", &op);




	return 0;
}
