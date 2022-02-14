#include <stdio.h>
#include <stdlib.h>

#define TAM 8

struct dado {
    int elemento;
    struct dado *prev;
};
typedef struct dado Dado;

typedef struct ponteiros {
    Dado *topo;
} Pilha;


Pilha incluiEle(Pilha pilha, int newDado) {

    Dado *novo;
    novo = (Dado *)malloc(sizeof(Dado));
    novo->elemento = newDado;
    novo->prev = NULL;

    if (pilha.topo == NULL) {
        pilha.topo = novo;
    }
    else {
        novo->prev = pilha.topo;
        pilha.topo = novo;
    }
    return pilha;
}
Pilha removeTopo(Pilha pilha) {

    Dado *aux; 
    aux = pilha.topo->prev;
    free(pilha.topo);
    pilha.topo = aux;

    return pilha;
};

void showPilha(Pilha pilha) {

    Dado *aux;
    printf("\nPilha -> ");
    for (aux = pilha.topo; aux != NULL; aux = aux->prev) {
        printf("%d, ", aux->elemento);
    }
    printf("\n");
    printf("-------------\n\n\n");
}



void DFS(int inicio, int destino, int matriz[TAM][TAM], Pilha pilha,  int anterior[TAM], int visitado[TAM], int distancia[TAM]) {

    int i = inicio, j;
    pilha = incluiEle(pilha, i);

    while (i != destino) {  

        printf("--------------\n");
        printf("Visitando -> %d\n", i);
        printf("--------------\n");
        printf("     vertice    |    visitado   | custo caminho |   anterior    |\n");

        for(int k = 0; k < TAM; k++) {
            printf("\t%d\t|\t%d\t|\t%d\t|\t%d\t|", k, visitado[k], distancia[k], anterior[k]);
            printf("\n");
        }
        for (int j = 0; j < TAM; j++) {
          if (matriz[i][j] == 1) {
              pilha = incluiEle(pilha, j);
              i = pilha.topo->elemento;
              break;
            }
          else {
            removeTopo(pilha);
            i = pilha.topo->elemento;
        }
        showPilha(pilha);
      }
    }
}

int main() {

    int inicio, destino;
    printf("--------------\n");
    printf("Defina o inicio\n");
    printf("-> ");
    scanf("%d", &inicio);
    printf("\n\n");
    printf("Defina o destino\n");
    printf("-> ");
    scanf("%d", &destino);
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
    
    Pilha pilha;
    pilha.topo = NULL;

    DFS(inicio, destino, matriz, pilha, anterior, visitado, distancia);


    return 0;
}