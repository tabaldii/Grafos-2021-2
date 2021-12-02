
// Anderson Henrique Grosselli Tabaldi
// Matricula: 2011100008

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void showMatrizSimple(int array[TAM][TAM]) {

    int i, j, k, grau = 0;
    printf("\n    ");

    for (k = 0; k < TAM; k++) {
        printf("%d ", k + 1);
    }

    printf("\n");

    for (k = 0; k < TAM; k++) {
        printf("---");
    }

    printf("\n");

    for (i = 0; i < TAM; i++) {

        printf("%d | ", i + 1);

        for (j = 0; j < TAM; j++) {

            printf("%d ", array[i][j]);

            if (array[i][j] == 1) {
                grau+=1;
            }
        }
        printf("| grau (%d)\n", grau);
        grau = 0;

    }
}

void showMatrizOriented(int array[TAM][TAM]) {

    int i, j, k, grauEntrada = 0, grauSaida = 0;
    printf("\n    ");

    for (k = 0; k < TAM; k++) {
        printf("%d ", k + 1);
    }
    
    printf("\n");
    for (k = 0; k < TAM; k++) {
        printf("---");
    }

    printf("\n");
    for (i = 0; i < TAM; i++) { 

        printf("%d | ", i + 1);

        for (j = 0; j < TAM; j++) {

            printf("%d ", array[i][j]);

            if (array[i][j] == 1) {
                grauSaida += 1;
            }

            if (array[j][i] == 1) {
                grauEntrada += 1;
            }
        }

        printf("| Saida(%d)", grauSaida);
        printf(" - Entrada(%d)", grauEntrada);

        if (grauSaida == 0) {
            printf(" - Eh sumidouro");
        }

        if (grauEntrada == 0) {
            printf(" - Eh fonte");
        }

        printf("\n");
        grauSaida = 0;
        grauEntrada = 0;

    }
}


int main() {

    int oriented = 0;

    int matriz [TAM][TAM] = {

        { 0, 1, 1, 0, 1},
        { 0, 0, 1, 1, 0},
        { 0, 0, 0, 1, 0},
        { 0, 0, 1, 0, 1},
        { 0, 0, 0, 0, 0}
    };

    printf("--------------\n");
    printf("O grafo eh orientado? \n    1 - Sim \n    0 - nao\n");
    printf("-> ");
    scanf("%d", &oriented);
    printf("--------------\n");

    if (oriented == 1) {
        showMatrizOriented(matriz);
    }

    else {
        showMatrizSimple(matriz);
    }

    return 0;
}