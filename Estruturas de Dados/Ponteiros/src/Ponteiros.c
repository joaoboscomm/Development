/*
 ============================================================================
 Name        : Ponteiros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/* Vari�vel vetor
	double 	salario[5] = {1500, 560, 7898, 4523, 963},
			*pontSalario;

	pontSalario = salario;

	printf("\n%.2lf\n", *pontSalario);

	pontSalario++;
	printf("\n%.2lf\n", *pontSalario);

	(*pontSalario)++;
	printf("\n%.2lf\n", *pontSalario);

	*/
	/* Vari�vel comum */
	int idade = 23;
	int *pontIdade = &idade;

	printf("\nEndere�o de mem�ria de idade (direto) %p\n", &idade);
	printf("\nEndere�o de mem�ria de idade (indireto) %p\n", pontIdade);
	printf("\nEndere�o de mem�ria de pontIdade  %p\n", &pontIdade);

	printf("\nConte�do da vari�vel idade (direto) %i\n", idade);
	printf("\nConte�do da vari�vel idade (indireto) %i\n", *pontIdade);


	return 0;
}
