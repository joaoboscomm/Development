/*
 ============================================================================
 Name        : Lista06NovosTipos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura de produto
struct produto{
	char descricao[40];
	int codigo;
	double preco;
	int quantidade;
};

//Novo tipo utilizando a estrutura anterior
typedef struct produto prod;

//Prot�tipo
void menu();
int validarInteiros(int limite, char *frase);
prod* alocarEstrutura(int *tam);
int criarCodigo();
void inserirProduto(prod *listaProdutos, int indice);
void criarDescricao(char *frase);
void criarPreco(prod *ficha);

//C�digos
int main(void) {
	setbuf(stdout, NULL);
	menu();
	return 0;
}

void menu(){
	int op,
	tamanho = 0,
	indice = 0;
	prod *produtos;

	do{
		printf("\n1 � Criar estrutura para preenchimento"
				"\n2 � Preencher dados"
				"\n3 � Exibir produtos com estoque zerado"
				"\n4 � Exibir produtos em estoque"
				"\n5 � Finalizar"
				"\nDigite sua op��o: ");
		fflush(stdin);
		scanf("%d", &op);

		switch(op) {
		case 1:
			if (tamanho == 0) {
				produtos = alocarEstrutura(&tamanho);
			} else {
				printf("\nEstrutura j� criada.");
			}
			break;
		case 2:
			if (tamanho > 0 && indice <= tamanho){
				inserirProduto(produtos, indice);
				indice++;
			} else if (tamanho == 0){
				printf("\nEstrutura n�o criada");
			} else {
				printf("\nTodos os produtos j� foram cadastrados.");
			}
			break;
		case 3:
			if (tamanho > 0){

			} else {
				printf("\nEstrutura j� criada.");
			}
			break;
		case 4:
			if (tamanho > 0){

			} else {
				printf("\nEstrutura j� criada.");
			}
			break;
		case 5:
			printf("\nPrograma finalizado");
			break;
		default:
			printf("\nOp��o inv�lida.");
		}



	} while (op != 5);
}

int validarInteiros(int limite, char *frase){
	int numero;
	do{
		printf("\n%s", frase);
		fflush(stdin);
		scanf("%d", &numero);

		if (numero <= limite){
			printf("\nValor inv�lido");
		}
	} while (numero <= limite);
	return numero;
}

prod* alocarEstrutura(int *tam){
	*tam = validarInteiros(0, "Digite a quantidade de produtos: ");
	prod *listaProd = (prod*) malloc (*tam * sizeof(prod));
	return listaProd;
}

void inserirProduto(prod *listaProdutos, int indice){
	listaProdutos[indice].codigo = criarCodigo();
	criarDescricao(listaProdutos[indice].descricao);
	criarPreco(&listaProdutos[indice]);
	listaProdutos[indice].quantidade = validarInteiros(-1, "Digite a quantidade em estoque: ");

	printf("\n%d - %s - %.2lf - %d\n",
			listaProdutos[indice].codigo,
			listaProdutos[indice].descricao,
			listaProdutos[indice].preco,
			listaProdutos[indice].quantidade);
}

int criarCodigo(){
	int codigo;

	printf("\nDigite o c�digo do produto: ");
	fflush(stdin);
	scanf("%d", &codigo);
	while (codigo < 0 || codigo > 50){
		printf("\nC�digo inv�lido. \nDigite o c�digo do produto: ");
		fflush(stdin);
		scanf("%d", &codigo);
	}
	return codigo;
}

void criarDescricao(char *frase){
	do{
		printf("\nDigite o nome do produto: ");
		fflush(stdin);
		gets(frase);

		if (strlen(frase) == 0){
			printf("\nValor inv�lido.");
		}
	} while (strlen(frase) == 0);
}

void criarPreco(prod *ficha){
	do{
		printf("\nDigite o pre�o do %s R$", ficha->descricao);
		fflush(stdin);
		scanf("%lf", &(ficha)->preco);

		if (ficha->preco < 0) {
			printf("\nValor inv�lido.");
		}
	} while (ficha->preco < 0);

}

void exibe(prod *ficha){

