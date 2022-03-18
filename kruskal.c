// Anderson Henrique Grosselli Tabaldi
// Matricula: 2011100008

// ???? Funciona em todos os compiladores online menos no VScode ??????

#include <stdio.h>
#include <stdlib.h>

#define TAM 8

typedef struct aresta {
	int origem;
	int destino;
	int peso;
} Arestas;

typedef struct lista {
	Arestas *aresta;
	struct lista *next;
} lista_arestas;

typedef struct {
	lista_arestas *lista_todas;
} Grafo;

typedef struct {
	int nodo[TAM];
	lista_arestas *lista_todas;
} Dados;

Grafo *init(){
	Grafo *grafo = malloc (sizeof(Grafo));
	grafo->lista_todas = NULL;
	return grafo;
}

Dados *initDado() {
  	Dados *dado = malloc (sizeof(Dados));
	int contador = 0;

	for (contador = 0; contador < TAM; contador++ ){ 
		dado->nodo[contador] = -1; 
  	}
	return dado;
}

lista_arestas *ordena_aresta(lista_arestas *listaAresta, int origem, int destino, int value){

	lista_arestas *aux, *ant = NULL;
	lista_arestas *new_element = malloc ( sizeof(lista_arestas) );

	new_element->aresta = malloc(sizeof(Arestas));
	new_element->aresta->origem = origem;
	new_element->aresta->destino = destino;
	new_element->aresta->peso = value;

	new_element->next = NULL;
	aux = listaAresta;

	while ( aux != NULL && aux->aresta->peso <= value ) {
		ant = aux;
		aux = aux->next;
	}

	if (ant == NULL) {
		new_element->next = listaAresta;
		listaAresta = new_element;

	} else {
		new_element->next = ant->next;
		ant->next = new_element;
	}
	return listaAresta;
}

lista_arestas *insertEdge(lista_arestas *listaAresta, Arestas *aresta){

	lista_arestas *aux;
    lista_arestas *new_element = malloc (sizeof(lista_arestas));
	new_element->aresta = aresta;


	if (listaAresta == NULL) {
		listaAresta = new_element;
	}
    else {
		aux = listaAresta;
		while (aux->next != NULL) { 
			aux = aux->next;
		}
		aux->next = new_element;
		new_element->next = NULL;		
	return listaAresta;
    }
}

void printDados(Dados *dado) {

	int i;
	printf("indice -> |");
	for (i = 0; i < TAM; i++) {
		printf(" %d \t|", i);
	}

	printf("\n");
	printf("raiz -> |  ");

	for (i = 0; i < TAM; i++) {
		printf(" %d \t|", dado->nodo[i]);
	}
	printf("\n\n");
}

void print_lista(lista_arestas *first) {

	lista_arestas *aux = first;
	printf("Caminho ate agora: ");
	while (aux != NULL){
		printf("(%d, %d), ", aux->aresta->origem, aux->aresta->destino);
		aux = aux->next;
	}
	printf("\n\n");
}

void kruskal(lista_arestas *listaAres, Dados *dado) {

	int orig, desti;
    lista_arestas *aux = listaAres;

	while (aux != NULL) {
		printf("\n---------- Estado atual ----------\n");
		orig = aux->aresta->origem;
		desti = aux->aresta->destino;

		if (dado->nodo[orig] >= 0) {
			orig = dado->nodo[orig];
		}
		if (dado->nodo[desti] >= 0) {
			desti = dado->nodo[desti];
		}

		printf("Visitando aresta: (%d --- %d --- %d)\n\n", aux->aresta->origem, aux->aresta->peso, aux->aresta->destino);
		if (orig != desti) {
			if ( dado->nodo[orig] < dado->nodo[desti] ) {
				dado->nodo[orig] += dado->nodo[desti];
				dado->nodo[desti] = orig;
			} else {
				dado->nodo[desti] += dado->nodo[orig];
				dado->nodo[orig] = desti;
			}
			dado->lista_todas = insertEdge(dado->lista_todas, aux->aresta);
		} 
		printDados(dado);
		print_lista(dado->lista_todas);
		aux = aux->next;
	}
}

int main() {

    int matriz [TAM][TAM] = {
            //0  1  2  3  4  5  6  7
    /*0*/   { 0, 3, 4, 3, 0, 0, 0, 0},
    /*1*/   { 0, 0, 0, 0, 0, 0, 0, 0},
    /*2*/   { 0, 0, 0, 0, 8, 8, 0, 0},
    /*3*/   { 0, 0, 0, 0, 0, 8, 0, 0},
    /*4*/   { 0, 0, 0, 0, 0, 0, 7, 7},
    /*5*/   { 0, 0, 0, 0, 0, 0, 4, 7},
    /*6*/   { 0, 0, 0, 0, 0, 0, 0, 2},
    /*7*/   { 0, 0, 0, 0, 0, 0, 0, 0},
    };

    Grafo *grafo = init();

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (matriz[i][j] != 0) {
                grafo->lista_todas = ordena_aresta(grafo->lista_todas, i, j, matriz[i][j]);
            }
        }
    }

    Dados *dado = initDado();
    kruskal(grafo->lista_todas, dado);

    return 0;
}