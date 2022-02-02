
// Anderson Henrique Grosselli Tabaldi
// Matricula: 2011100008


#include <stdio.h>
#include <stdlib.h>

#define TAM 8

struct Fila {

    int topo;
    int fim;
    struct Fila *prev;

};

typedef struct Fila fila;



void showBFS (int variaveis[TAM][3], int matriz[TAM][TAM]) {
    

}


void BFS(int inicio, int matriz[TAM][TAM], int fila[TAM],  int anterior[TAM], int visitado[TAM], int distancia[TAM]) {

    int i, j;
    fila[0] = inicio;

    while (fila[0] == 0) {


    }

    for (i = inicio; i < TAM; i++) {

        if (variaveis[i][1] != 1) {
            variaveis[i][1] = 1;
            adicionaFila(i)
        }
        else {
            return;
        }

        printf("Visitando -> %d\n", i);
        printf("------------\n");
        printf("     vertice    |    visitado  |     valor de caminho    |   anterior    |\n");

        for(int i = 0; i < TAM; i++) {
            printf("\t%d\t|\t%d\t|\t%d\t|\t%d\t|", i, variaveis[i][1], variaveis[i][2], variaveis[i][0]);
            printf("\n");
        }

        for (j = 0; j < TAM; j++) {
                if (matriz[i][j] != 0) {
                    
                }
        }
    }

}

int main() {

    int inicio;
    printf("--------------\n");
    printf("Defina o inicio\n");
    printf("-> ");
    scanf("%d", &inicio);
    printf("\n");
    printf("--------------\n");


    int matriz [TAM][TAM] = {
            //0  1  2  3  4  5  6  7
    /*0*/ { 0, 4, 7, 4, 0, 0, 0, 0},
    /*1*/ { 0, 0, 0, 0, 0, 0, 0, 0},
    /*2*/ { 0, 2, 0, 0, 0, 0, 0, 0},
    /*3*/ { 0, 0, 0, 0, 0, 0, 0, 9},
    /*4*/ { 0, 0, 9, 0, 0, 0, 0, 0},
    /*5*/ { 0, 1, 0, 8, 0, 0, 0, 0},
    /*6*/ { 0, 0, 6, 0, 0, 0, 0, 9},
    /*7*/ { 0, 0, 0, 0, 0, 3, 0, 0}
    };


    int anterior[TAM], visitado[TAM], distancia[TAM];
    
    for (int i = 0; i < TAM; i++) {
        anterior[i] = -1;
        visitado[i] = 0;
        distancia[i] = 100;
    }

    Fila fila;
    
    BFS(inicio, matriz, fila, anterior, visitado, distancia);


    return 0;
}