// Anderson Henrique Grosselli Tabaldi
// Matricula: 2011100008

#include <stdio.h>
#include <stdlib.h>

#define TAM 8

struct arestas {
    int origem;
    int destino;
    int peso;
    struct arestas *prev;
};
typedef struct arestas Arestas;

struct lista {
  Arestas *ultimo;
};
typedef struct lista lista_arestas;


void preenche_arestas(lista_arestas lista_arestas, int matriz[TAM][TAM]){

  Arestas *nova_aresta;
  nova_aresta = (Arestas *)malloc(sizeof(Arestas));
  
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      if (matriz[i][j] != 0) {
          nova_aresta->origem = i;
          nova_aresta->destino = j;
          nova_aresta->peso = matriz[i][j];
        if (lista_arestas.ultimo == NULL){
            lista_arestas.ultimo = nova_aresta;
          }
        else {
            nova_aresta->prev = lista_arestas.ultimo;
            lista_arestas.ultimo = nova_aresta;
        }        
      }
    }
  }
}

void ordena_aresta(lista_arestas lista_arestas){
  Arestas *aux;
  aux = (Arestas *)malloc(sizeof(Arestas));

  while (lista_arestas.ultimo->prev != NULL) {
        if (lista_arestas.ultimo->peso < lista_arestas.ultimo->prev->peso) {
          aux = lista_arestas.ultimo->prev;
          lista_arestas.ultimo->prev = aux->prev;
          aux->prev = lista_arestas.ultimo;
          lista_arestas.ultimo = aux;
        }
        lista_arestas.ultimo = lista_arestas.ultimo->prev;
    }
  }
void show_lista() {

  
}

int main() {


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
  
  lista_arestas lista;
  lista.ultimo = NULL;
  
  return 0;