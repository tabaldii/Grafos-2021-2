
// Anderson Henrique Grosselli Tabaldi
// Matricula: 2011100008

#include <stdio.h>
#include <stdlib.h>

#define TAM 8
/*
int achaMenor(int array[TAM][TAM],int inicio) {

    int i, j;
    int valor[TAM];
    int visitados[TAM];
    int anterior[TAM];
    

    for (i = inicio; i == inicio; i++) {
        
        printf("Estou no nodo %d, ", i+1);

        for (j = 1; j < TAM; j++) {

            if (array[i][j] != 0) {
                if (array[i][j] < menor){
                    menor = array[i][j];
                    posMenor = j;
                }
            }
            else if (menor == 50000000 && j == TAM){
                return 0; 
            }
        }
        printf("indo para o nodo %d por %d\n", posMenor+1, menor);
        return(posMenor);
    }
}
*/
void printDijkstra(int valor[TAM], int atual, int anterior[TAM], int visitados[TAM]){

    printf("     vertice    |    visitados  |     valor     |   anterior    |\n");

    for(int i = 0; i < TAM; i++) {
        printf("\t%d\t|\t%d\t|\t%d\t|\t%d\t|", i, visitados[i], valor[i], anterior[i]);
        printf("\n");
    }
}

void dijkstra(int array[TAM][TAM], int inicio, int visitado[TAM], int anterior[TAM], int distancia[TAM]) {

    visitado[inicio] = 1;
    distancia[inicio] = 0;

    int j = inicio, i;

    while (j < TAM) {
        printf("Visitando -> %d\n", j);
        printDijkstra(distancia, inicio, anterior, visitado);
        
        j++;
    }

    
/*

    int novoInicio, i = 0;
    novoInicio = achaMenor(array, inicio);
    if (novoInicio == 0) {
        printf("Impossivel com guloso!\n");
        return;
    }
    else if (i == TAM){
        printf("Cansei, impossivel com guloso!\n");
        return;
    }
   
    dijkstra(array, novoInicio);
    i++;*/
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

    int i, j;

    for (i = 0; i < TAM; i++) {

        anterior[i] = -1;
        visitado[i] = 0;
        distancia[i] = 100;

    }

    dijkstra(matriz, inicio, visitado, anterior, distancia);

    return 0;
}