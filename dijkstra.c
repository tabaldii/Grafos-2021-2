
// Anderson Henrique Grosselli Tabaldi
// Matricula: 2011100008

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TAM 8

void printDijkstra(int valor[TAM], int anterior[TAM], int visitados[TAM]){

    printf("     vertice    |    visitados  |     valor     |   anterior    |\n");

    for(int i = 0; i < TAM; i++) {
        printf("\t%d\t|\t%d\t|\t%d\t|\t%d\t|", i, visitados[i], valor[i], anterior[i]);
        printf("\n");
    }
}

int achaMenor(int distancia[TAM], int visitados[TAM]) {

    int menor = 100;
    int i;
    int posMenor;
    for (i = 0; i < TAM; i++) {
        if (visitados[i] == 0 && distancia[i] < menor) {
            menor = distancia[i];
            posMenor = i;
        }
    }

    if (menor == 100){
        return -1;
    }
    return posMenor;
}



void dijkstra(int array[TAM][TAM], int inicio, int visitado[TAM], int anterior[TAM], int distancia[TAM]) {

    distancia[inicio] = 0;
    int j = inicio;

    while (j < TAM) {

        visitado[j] = 1;
        printf("Visitando -> %d\n", j);
        for(int i = 0; i < TAM; i++){
            if(array[j][i] != 0 && visitado[i] != 1 && (array[j][i] + distancia[j]) < distancia[i]){
                distancia[i] = array[j][i] + distancia[j];
                anterior[i] = j;
            }
        }

        printDijkstra(distancia, anterior, visitado);
        
        int menor = achaMenor(distancia, visitado);
        
        if (menor == -1 || menor > TAM){
            return;
        }
        j = menor;
    }
}

int main() {

    int inicio;
    int anterior[TAM], visitado[TAM], distancia[TAM];

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

    int i;

    for (i = 0; i < TAM; i++) {
        anterior[i] = -1;
        visitado[i] = 0;
        distancia[i] = 100;
    }

    dijkstra(matriz, inicio, visitado, anterior, distancia);

    return 0;
}