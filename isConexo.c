
// Anderson Henrique Grosselli Tabaldi
// Matricula: 2011100008

#include <stdio.h>
#include <stdlib.h>

#define TAM 8

void percorre(int matriz[TAM][TAM], int vetor[TAM], int inicio) {

    vetor[inicio]++;

    for (int i = 0; i < TAM; i++) {
        if (!vetor[i] && matriz[inicio][i]) {
            percorre(matriz, vetor, i);
        }
    }
}

int isConexo(int matriz[TAM][TAM], int inicio) {

    int vetor[TAM];
    int cont = 0;

    for (int i = 0; i < TAM; i++) {
        vetor[i] = 0;
    }

    percorre(matriz, vetor, inicio);

    for (int j = 0; j < TAM; j++) {
        if (vetor[j] == 1) {
            cont++;
        }
    }

    if (cont == TAM) {
        return 1;
    }

    else {
        return 0;
    }
}

int main() {

    int inicio;
    printf("--------------\n");
    printf("Defina o inicio\n");
    printf("-> ");
    scanf("%d", &inicio);
    printf("--------------\n");
    printf("\n");

    int matriz[TAM][TAM] = {
        // 0  1  2  3  4  5  6  7
        /*0*/ {0, 1, 1, 1, 0, 0, 0, 0},
        /*1*/ {1, 0, 1, 0, 0, 1, 0, 0},
        /*2*/ {1, 1, 0, 0, 0, 1, 0, 0},
        /*3*/ {1, 0, 0, 0, 0, 1, 0, 0},
        /*4*/ {0, 0, 0, 0, 0, 0, 0, 1},
        /*5*/ {0, 1, 1, 1, 0, 0, 1, 0},
        /*6*/ {0, 0, 0, 0, 0, 1, 0, 1},
        /*7*/ {0, 0, 0, 0, 1, 0, 1, 0},
    };

    if (isConexo(matriz, inicio) == 1) {
        printf("********************\n");
        printf("O grafo EH conexo!!!\n");
        printf("********************\n");
    }

    else {
        printf("********************\n");
        printf("o grafo NAO eh conexo!!!\n");
        printf("********************\n");
    }

    return 0;
}