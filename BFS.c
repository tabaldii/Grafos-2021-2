
// Anderson Henrique Grosselli Tabaldi
// Matricula: 2011100008

#include <stdio.h>
#include <stdlib.h>

#define TAM 8

struct dado {
    int elemento;
    struct dado *next;
};
typedef struct dado Dado;

typedef struct ponteiros {
    Dado *primeiro;
    Dado *ultimo;
} Fila;


Fila incluiEle(Fila fila, int newDado) {

    Dado *novo;
    novo = (Dado *)malloc(sizeof(Dado));
    novo->elemento = newDado;
    novo->next = NULL;

    if (fila.primeiro == NULL) {
        fila.ultimo = novo;
        fila.primeiro = novo;
    }
    else {
        fila.ultimo->next = novo;
        fila.ultimo = novo;
    }
    return fila;
}

Fila removeEle(Fila fila) {

    Dado *aux; 
    aux = fila.primeiro->next;
    free(fila.primeiro);
    fila.primeiro = aux;

    return fila;
};

void showFila(Fila fila) {

    Dado *aux;
    printf("\nFila -> ");
    for (aux = fila.primeiro; aux != NULL; aux = aux->next) {
        printf("%d, ", aux->elemento);
    }
    printf("\n");
    printf("-------------\n\n\n");
}

void BFS(int inicio, int matriz[TAM][TAM], Fila fila,  int anterior[TAM], int visitado[TAM], int distancia[TAM]) {

    int i = inicio, j;
    fila = incluiEle(fila, inicio);
    visitado[i] = 1;

    while (fila.primeiro != NULL) {

        fila = removeEle(fila);
        printf("--------------\n");
        printf("Visitando -> %d\n", i);
        printf("--------------\n");
        printf("     vertice    |    visitado   | custo caminho |   anterior    |\n");

        for(int k = 0; k < TAM; k++) {
            printf("\t%d\t|\t%d\t|\t%d\t|\t%d\t|", k, visitado[k], distancia[k], anterior[k]);
            printf("\n");
        }

        for (j = 0; j < TAM; j++) {
            if (matriz[i][j] == 1) {
                if (visitado[j] != 1) {
                    visitado[j] = 1;
                    fila = incluiEle(fila, j);
                    distancia[j] = distancia[i] + 1;
                    anterior[j] = i;
                }
            }
        }
        showFila(fila);
        i = fila.primeiro->elemento;
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
    /*0*/   { 0, 0, 0, 1, 0, 0, 0, 0},
    /*1*/   { 1, 0, 1, 0, 0, 0, 1, 0},
    /*2*/   { 1, 0, 0, 0, 1, 1, 0, 0},
    /*3*/   { 0, 1, 0, 0, 0, 0, 0, 0},
    /*4*/   { 0, 0, 1, 0, 0, 0, 0, 0},
    /*5*/   { 0, 1, 0, 0, 0, 0, 0, 1},
    /*6*/   { 0, 0, 1, 0, 0, 1, 0, 1},
    /*7*/   { 0, 0, 0, 0, 0, 0, 0, 0},
    };


    int anterior[TAM], visitado[TAM], distancia[TAM];
    
    for (int i = 0; i < TAM; i++) {
        anterior[i] = -1;
        visitado[i] = 0;
        distancia[i] = 0;
    }
    
    Fila fila;
    fila.primeiro = NULL;
    fila.ultimo = NULL;

    BFS(inicio, matriz, fila, anterior, visitado, distancia);


    return 0;
}
