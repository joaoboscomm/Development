/*
 ============================================================================
 Name        : Lista08.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Quest�o 01
int multiplicarSomando(int x, int y);
int multiplicarSomandoCauda(int x, int y, int parcial);

//Quest�o 02
void exibirTabuada(int n, int q);

//Quest�o 03
double calcularSerie(int n);
double calcularSerieCauda(int n, double parcial);

//Quest�o Extra
int potencia(int base, int expoente);

//Quest�o 04
int somarVetor(int *vet, int tam);
int somarVetorCauda (int *vet, int tam, int parcial);

//Quest�o 05
void baseBinaria(int n, int tam);

int main(void) {
	setbuf(stdout, NULL);

	//Quest�o 01
	printf("\nQuest�o 01\n");
	printf("\nExerc�cio 01 - 5 * 7 = %d (recursividade normal)\n", multiplicarSomando(5,7));
	printf("\nExerc�cio 01 - 5 * 7 = %d (recursividade cauda)\n", multiplicarSomandoCauda(5, 7, 0));

	//Quest�o 02
	printf("\nQuest�o 02\n");
	exibirTabuada(5, 6);
	//N�o � poss�vel fazer em cauda, n�o tem resultado parcial.

	//Quest�o 03
	printf("\nQuest�o 03\n");
	printf("\nO c�lculo da s�rie � %.2lf (Recursividade normal)\n", calcularSerie(4));
	printf("\nO c�lculo da s�rie � %.2lf (Recursividade cauda)\n", calcularSerieCauda(4, 0));

	//Quest�o extra
	printf("\nQuest�o Extra\n");
	printf("\nPotencia 2 ^ 5 = %d\n", potencia(2,5));

	//Quest�o 04
	printf("\nQuest�o 04\n");
	int vet[] = {25, 9, 13, 18, 5};
	printf("\nA soma dos elementos � %d (Recursivo normal)\n", somarVetor(vet, 5));
	printf("\nA soma dos elementos � %d (Recursivo cauda)\n", somarVetorCauda(vet, 5, 0));

	//Quest�o 05
	printf("\nQuest�o 05\n");
	printf("\nN�mero bin�rio para o 65 = ");
	baseBinaria(65, 8);
	return 0;
}

//Quest�o 01
int multiplicarSomando(int x, int y){
	if (x == 1){
		return y;
	} else {
		return y + multiplicarSomando(x-1, y);
	}
}

int multiplicarSomandoCauda(int x, int y, int parcial){
	if (x == 0){
		return parcial;
	} else {
		return multiplicarSomandoCauda(x - 1, y, parcial + y);
	}
}

//Quest�o 02
void exibirTabuada(int n, int q){
	if (q == 1) {
		printf("\n%d * %d = %d\n", n, q, n * q);
	} else {
		exibirTabuada(n, q-1);
		printf("\n%d * %d = %d\n", n, q, n * q);
	}

	/* Outra solu��o para o mesmo exerc�cio
	if (q != 1) {
		exibirTabuada(n, q-1);
	}
	printf("\n%d * %d = %d\n", n, q, n * q);
	*/
}

//Quest�o 03
double calcularSerie(int n){
	if (n == 1) {
		return pow(n, 3) / pow(10, n-1);
	} else {
		return pow(n, 3) / pow(10, n-1) + calcularSerie(n-1);
	}
}

double calcularSerieCauda(int n, double parcial){
	if (n == 1) {
		return parcial + pow(n, 3) / pow(10, n-1);
	} else {
		return calcularSerieCauda(n-1, parcial +
								  	    pow(n, 3) / pow(10, n-1));
	}
}

//Quest�o Extra
int potencia(int base, int expoente){
	if (expoente == 1) {
		return base;
	} else {
		return base * potencia(base, expoente - 1);
	}

}


//Quest�o 04
int somarVetor(int *vet, int tam){
	if (tam == 1) {
		return *vet;
	} else {
		return *vet + somarVetor(++vet, tam - 1);
		/*
		 vet++;
		 return *vet + somarVetor(vet, tam - 1);
		*/
	}
}

int somarVetorCauda (int *vet, int tam, int parcial) {
	if (tam == 1) {
		return parcial + *vet;
	} else {
		return somarVetorCauda(++vet, tam-1, parcial + *vet);
	}
}

//Quest�o 05
void baseBinaria(int n, int tam){
	if (tam == 1) {
		printf("%d", 0);
	}else {
		baseBinaria(n / 2, tam-1);
		printf("%d", n % 2);
	}
}



