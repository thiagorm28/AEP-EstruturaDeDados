#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Criando o Struct do tipo especie planta
typedef struct tipoEspeciePlanta {
	char nomeEspecie[40];
	char tipo[20];
    char tipoColheita[200];
    char tipoIrrigacao[200];
    char tipoSolo[150];
    char observacoesExtras[400];
	struct tipoEspeciePlanta *proximo;
}TEspeciePlanta;


typedef struct tipoLista {
	TEspeciePlanta *inicio;
	TEspeciePlanta *fim;
}TLista;

//Criando a tabela hashing
TLista tabelaHashing[10];

//Inicializando as listas da tabela hashing
void inicializar() {
	for (int cont = 0; cont < 10; cont++) {
		tabelaHashing[cont].inicio = NULL;
		tabelaHashing[cont].fim = NULL;
	}
}

//Função hash
int hash(int valor) {
	return valor % 10;
}

//Função para inserir os elementos nas lista encadeadas da tabela
void inserir(TEspeciePlanta *nova, int indice) {
	if (tabelaHashing[indice].inicio == NULL) {
		tabelaHashing[indice].inicio = nova;
		tabelaHashing[indice].fim = nova;
	}
	else {
		tabelaHashing[indice].fim->proximo = nova;
		tabelaHashing[indice].fim = nova;
	}
}

//Lendo os dados das espécies que serão inseridas
void lerDados (TEspeciePlanta *nova)
{
	fflush(stdin);
	printf("\n Informe a espécie da planta: ");
	gets(nova->nomeEspecie);
	fflush(stdin);
	printf("\n Informe o tipo da planta: ");
	gets(nova->tipo);
	fflush(stdin);
	printf("\n Informe o tipo de colheita da planta: ");
	gets(nova->tipoColheita)
	fflush(stdin);
	printf("\n Informe o tipo de irrigacao que a planta precisa: ");
	gets(nova->tipoIrrigacao);
	fflush(stdin);
	printf("\n Informe o tipo de solo bom para plantar a planta: ");
	gets(nova->tipoSolo);
	fflush(stdin);
	printf("\n Informe as observações extras da planta: ");
	gets(nova->observacoesExtras);
}

//Execuntando a função hashing e inserindo o elemento no lugar certo do vetor e nas listas encadeadas caso ocorra colisões
void executar() {
	TEspeciePlanta *nova;
	nova = new TEspeciePlanta;
	lerDados(nova);
	int quantLetras = 3;
	
	int soma = 0;
	for (int cont = 0; cont < quantLetras && nova->nomeEspecie != '\0'; cont++) {
		soma += nova->nomeEspecie[cont];
	}
	int indice = hash(soma);
		
	nova->proximo = NULL;
	inserir(nova, indice);
}

//Apresentando a tabela completa
void apresentar() {
	for (int cont = 0; cont < 10; cont++) {
		TEspeciePlanta *aux;
		aux = tabelaHashing[cont].inicio;
		if (aux != NULL) {
			printf("\nIndice: %d -> ", cont);
			while (aux != NULL) {
				printf("%s - ", aux->nomeEspecie);
				aux = aux->proximo;
			}
		}
		else {
			printf("\nIndice: %d vazio", cont);
		}
	}
}

int main() {
	int opcao;
	inicializar();
	do {
		printf("\n1 - Executar hash");
		printf("\n2 - Apresentar tabela hashing");
		printf("\n0 - Sair\n");
		scanf("%d", &opcao);
		switch(opcao) {
			case 1: executar(); break;
			case 2: apresentar(); break;
		}
	}while (opcao != 0);
}
