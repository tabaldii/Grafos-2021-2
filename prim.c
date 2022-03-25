// Anderson Henrique Grosselli Tabaldi
// Matricula: 2011100008

#include <stdio.h>
#include <stdlib.h>

#define TAM 8

int posMenor(int valor[], int visitado[]) {

	int menor = 100;
	int index_menor;

	for (int j = 0; j < TAM; j++) {
		if (visitado[j] == 0 && valor[j] < menor) {
			menor = valor[j];
			index_menor = j;
		}
	}
	return index_menor;
}

int showPrim(int anterior[], int matriz[TAM][TAM], int visitado[], int valor[]) {

	printf("     vertice    |    visitados  |     valor     |   anterior    |\n");
	for (int i = 0; i < TAM; i++) {
	    printf("\t%d\t|\t%d\t|\t%d\t|\t%d\t|", i, visitado[i], valor[i], anterior[i]);
		printf("\n");
	}
}


void prim(int matriz[TAM][TAM], int inicio) {

	int anterior[TAM];
	int valor[TAM];
	int visitado[TAM];

	for (int i = 0; i < TAM; i++) {
		valor[i] = 100;
		visitado[i] = 0;
		anterior[i] = -1;
	}

	valor[inicio] = 0;
	int i = inicio;

	for (int x = 0; x < TAM-1; x++) {

		int i = posMenor(valor, visitado);
		printf("-----------------------\n");
		printf("Visitando: %d\n", i);
		printf("-----------------------\n");

		visitado[i] = 1;
		for (int j = 0; j < TAM; j++) {
			if (matriz[i][j] && visitado[j] == 0 && matriz[i][j] < valor[j]) {
				anterior[j] = i;
				valor[j] = matriz[i][j];
			}
		}
		showPrim(anterior, matriz, visitado, valor);
	}

}

int main() {

	int inicio = 0;
	printf("Defina o inicio -> ");
	scanf("%d", &inicio);

	int matriz[TAM][TAM] = { 
          //0  1  2  3  4  5  6  7
    /*0*/ { 0, 0, 8, 0, 0, 0, 0, 0},
    /*1*/ { 0, 0, 9, 1, 0, 0, 8, 0},
    /*2*/ { 8, 9, 0, 0, 0, 0, 1, 0},
    /*3*/ { 0, 1, 0, 0, 0, 0, 0, 2},
    /*4*/ { 0, 0, 0, 0, 0, 0, 5, 6},
    /*5*/ { 0, 0, 0, 0, 0, 0, 0, 0},
    /*6*/ { 8, 0, 1, 0, 5, 0, 0, 8},
    /*7*/ { 0, 0, 0, 2, 6, 0, 8, 0}

    };

	prim(matriz, inicio);

	return 0;
}
