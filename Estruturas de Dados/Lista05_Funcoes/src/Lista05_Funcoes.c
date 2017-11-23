/*
 ============================================================================
 Name        : Lista05_Funcoes.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Prot�tipos
void menu();
int validarInteiro();
void calcularSalarioEncanador(int dias, double *pontSalario);
double calcularNovoSalario(double novoSalario);
double calcularSalarioVetor(double *vet, int tam);


int main(void) {
	setbuf(stdout, NULL);
	menu();
	return 0;
}

void menu(){
	char 	op = 'V';
	double 	salario,
			resultado,
			*pVet;
	int 	dias,
			tam;

	while (op != 'C'){
		printf("\nA - Resultado da fun��o 04"
				"\nB - Resultado da fun��o 05"
				"\nC - Finalizar"
				"\nDigite sua op��o: ");
		fflush(stdin);
		scanf("%c", &op);

		switch (op){
		case 'A' :
			//chamada da fun��o 04
			dias = validarInteiro(0);
			calcularSalarioEncanador(dias, &salario);
			//calcularSalarioEncanador(validarInteiro(), pontSalario)
			break;
		case 'B':
			//Chamada da fun��o 05
			tam = validarInteiro(1);
			pVet = (double *) malloc (tam * sizeof(double));
			resultado = calcularSalarioVetor(pVet, tam);
			printf("\nA m�dia dos sal�rios � R$%.2lf", resultado);
			//printf("\nA m�dia dos sal�rios � R$%.2lf", calcularSalarioVetor(pVet, tam));
			break;
		case 'C':
			printf("\nPrograma finalizado.");
			break;
		default:
			printf("\nOp��o inv�lida.");
			break;
		}
	}
}

int validarInteiro(int limite){
	int numero;
	do{
		printf("\nDigite um n�mero: ");
		fflush(stdin);
		scanf("%i", &numero);

		if (numero < limite) {
			printf("\nValor inv�lido");
		}
	} while (numero < limite);

	return numero;
}

double validarReal(){
	double numero;
	printf("\nDigite o valor: ");
	fflush(stdin);
	scanf("%lf", &numero);

	while (numero <= 0){
		printf("\nValor inv�lido. Digite novamente: ");
		fflush(stdin);
		scanf("%lf", &numero);
	}

	return numero;
}

void calcularSalarioEncanador(int dias, double *pontSalario){
	*pontSalario = dias * 30;
	*pontSalario -= *pontSalario * 0.08;
	//*pontSalario *= 0.92;
}


double calcularNovoSalario(double novoSalario){
	if (novoSalario <= 1500){
		novoSalario *= 1.15;
	} else if (novoSalario <= 5000){
		novoSalario *= 1.1;
	} else if (novoSalario <= 15000){
		novoSalario *= 1.05;
	}

	return novoSalario;
}

double calcularSalarioVetor(double *vet, int tam){
	int i;
	double media = 0;

	//Aritm�tica de ponteiros
	for (i = 0; i < tam; i++) {
		*vet = validarReal();
		*vet = calcularNovoSalario(*vet);
		media += *vet;
		vet++;
	}

	/*
	//Manipula��o de �ndice de vetor
	for (i = 0; i < tam; i++) {
		vet[i] = validarReal();
		vet[i] = calcularNovoSalario(vet[i]);
		media += vet[i];
	}
	*/

	return media / tam;
}





