
// Anderson Henrique Grosselli Tabaldi
// Matricula: 2011100008

#include <stdio.h>
#include <stdlib.h>

#define TAM 7


void guloso(int array[TAM][TAM], int inicio, int objetivo) {

    int i, j = 0;
    int passos = 0;
    int menor = 50000000;
    int posMenor = 0;

    for (i = inicio; i != objetivo; i++) {
        
        printf("Estou no nodo %d, ", i);

        if (passos == TAM){
            printf("Cansei, impossivel fazer com guloso!\n");
        }

        for (j = 0; j < TAM; j++) {

            if (array[i][j] != 0) {
                if (array[i][j] < menor) {
                    menor = array[i][j];
                    posMenor = j;
                }
            }
            else {
                if (j == TAM){
                    printf("Impossivel com guloso!\n");
                    break;
                }
            }
        }
        printf("indo para o nodo %d por %d\n", posMenor, menor);
        inicio = posMenor;
        passos ++;
    }
    /*
    for (i = 0; i < TAM; i++) { 

        for (j = 0; j < TAM; j++) {

            printf("%d ", array[i][j]);

            if (array[i][j] == 1) {
                
            }

            if (array[j][i] == 1) {
                
            }
        }
    }*/

    
}

int main() {

    int inicio, objetivo;

    printf("--------------\n");
    printf("Defina o inicio\n");
    printf("-> ");
    scanf("%d", &inicio);
    printf("\n");
    printf("Defina o objetivo\n");
    printf("-> ");
    scanf("%d", &objetivo);   
    printf("--------------\n");

    int matriz [TAM][TAM] = {

          //1  2  3  4  5  6  7
    /*1*/ { 0, 2, 0, 6, 12, 0, 0},
    /*2*/ { 0, 0, 1, 0, 0, 5, 0},
    /*3*/ { 0, 0, 0, 0, 0, 0, 40},
    /*4*/ { 0, 0, 0, 0, 0, 4, 0},
    /*5*/ { 0, 0, 0, 0, 0, 0, 30},
    /*6*/ { 0, 0, 0, 0, 0, 0, 8},
    /*7*/ { 0, 0, 0, 0, 0, 0, 0}

    };

    guloso(matriz, inicio, objetivo);

    return 0;
}