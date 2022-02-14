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



void DFS(int inicio, int destino, int matriz[TAM][TAM], Pilha pilha,  int anterior[TAM], int fechado[TAM], int entrada[TAM], int saida[TAM], int visitado[TAM]) {

    int i = inicio;
    int contador = 1;
    pilha = incluiEle(pilha, i);
    visitado[i] = 1;
    entrada[i] = 1;

    while (i != destino || pilha.topo != NULL) {  

        contador++;
        printf("--------------\n");
        printf("Visitando -> %d\n", i);
        printf("--------------\n");
        printf("     vertice    |    fechado    |    entrada    |     saida     |   anterior    |\n");

        for(int k = 0; k < TAM; k++) {
            printf("\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|", k, fechado[k], entrada[k], saida[k], anterior[k]);
            printf("\n");
        }

        showPilha(pilha);
        printf("--------------\n");
        printf("Destino -> %d\n", destino);
        printf("--------------\n");
        for (int j = 0; j < TAM; j++) {

            if (matriz[i][j] == 1 && fechado[j] != 1) {
                if (visitado[j] != 1) {
                    pilha = incluiEle(pilha, j);
                    entrada[j] = contador;
                }
                visitado[j] = 1;
                anterior[j] = i;
                i = j;
                break;
            }

            else if (j == TAM-1) {
                fechado[i] = 1;
                pilha = removeTopo(pilha);
                i = pilha.topo->elemento;
                saida[i] = contador;
            }
        }


        if (i == destino) {
            printf("**************************\n");
            printf("Chegamos ao destino pelo %d!\n", pilha.topo->prev->elemento);
            printf("**************************\n");
            return;
        }
        if (fechado[inicio] == 1){
            printf("Não conseguimos chegar ao destino!!!\n");
            return;
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
    /*0*/   { 0, 1, 0, 0, 0, 0, 0, 0},
    /*1*/   { 0, 0, 1, 1, 0, 0, 0, 0},
    /*2*/   { 0, 0, 0, 0, 1, 0, 0, 0},
    /*3*/   { 0, 0, 0, 0, 0, 1, 0, 0},
    /*4*/   { 0, 0, 0, 0, 0, 0, 0, 0},
    /*5*/   { 0, 0, 0, 0, 0, 0, 0, 1},
    /*6*/   { 0, 0, 0, 0, 0, 1, 0, 0},
    /*7*/   { 0, 0, 0, 0, 0, 0, 0, 0},
    };


    int anterior[TAM], fechado[TAM], entrada[TAM], saida[TAM], visitado[TAM];
    
    for (int i = 0; i < TAM; i++) {
        anterior[i] = -1;
        visitado[i] = 0;
        fechado[i] = 0;
        entrada[i] = 0;
        saida[i] = 0;
    }
    
    Pilha pilha;
    pilha.topo = NULL;

    DFS(inicio, destino, matriz, pilha, anterior, fechado, entrada, saida, visitado);

    return 0;
}