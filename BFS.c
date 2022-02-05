
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

    Dado *aux = fila.primeiro;
    printf("Fila -> ");
    while (aux->next != NULL) {
        printf("%d, ", aux->elemento);
    }
    
}

void BFS(int inicio, int matriz[TAM][TAM], Fila fila,  int anterior[TAM], int visitado[TAM], int distancia[TAM]) {

    int i, j;
    fila = incluiEle(fila, inicio);

    while (fila.primeiro->next != NULL) {

        for (i = inicio; i < TAM; i++) {

            if (visitado[i] != 1) {

                visitado[i] = 1;
                if (i != inicio) {
                    fila = incluiEle(fila, i);
                }
            }

            else {
                return;
            }

            printf("Visitando -> %d\n", i);
            printf("------------\n");
            printf("     vertice    |    visitado  |     valor de caminho    |   anterior    |\n");

            for(int i = 0; i < TAM; i++) {
                printf("\t%d\t|\t%d\t|\t%d\t|\t%d\t|", i, visitado[i], distancia[i], anterior[i]);
                printf("\n");
            }
            showFila(fila);
            /*
            for (j = 0; j < TAM; j++) {
                    if (matriz[i][j] != 0) {
                        
                    }
            }
            */
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


    int anterior[TAM], visitado[TAM], distancia[TAM], fila[TAM+1];
    
    for (int i = 0; i < TAM; i++) {
        anterior[i] = -1;
        visitado[i] = 0;
        distancia[i] = 100;
    }
    
    Fila fila;

    BFS(inicio, matriz, fila, anterior, visitado, distancia);


    return 0;
}