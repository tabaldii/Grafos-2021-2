#include <stdio.h>
#include <stdlib.h>

#define TAM 8

typedef struct {

  int topo;
  int fim;
  struct Fila *next;

} Fila;


void queue () {

}



void BFS (int inicio, Fila fila, int variaveis[TAM][4], int matriz[TAM][TAM]) {



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



  int variaveis [TAM][4];   //vmatriz guarda variaveis
  /*
  0 -> anterior
  1 -> já visitados 
  2 -> não visitados
  3 -> valores acumulados
  */

  for (int i = 0; i < 4; i++) {     //inicializa a matriz
    for (int j = 0; j < TAM; j++){
      variaveis[i][j] = 0;
    }
  }

  Fila fila;
  
  BFS(inicio, fila, variaveis, matriz);


  return 0;
}