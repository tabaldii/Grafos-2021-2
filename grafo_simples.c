#include<stdio.h>
#include<stdlib.h>

/*
 Vertex linked list
*/
struct _vertex {
    int value;
    int entry_grade;
    int output_degree;
    struct _vertex *next;
};
typedef struct _vertex Vertex;

/*
 Edge linked list
*/

struct _edge {
    Vertex *s;
    Vertex *d;
    struct _edge *next;
};
typedef struct _edge Edge;

typedef struct {
    int oriented;
    Vertex *vertexes; //primeiro elemento da lista de vértices
    Edge *edges; //primeiro elemento da lista de arestas
} Graph;

Vertex *insertVertex(Vertex *head, int value){

    Vertex *new = malloc (sizeof(Vertex));
    new->value = value;
    new->next = head;
    new->entry_grade = 0;
    new->output_degree = 0;
    return new;
}

Edge *insertEdge(Graph *graph, int v_origem, int v_destino) {

    Edge *newA = malloc(sizeof(Edge));
    Vertex *auxV;  

    for (auxV = graph->vertexes; auxV!=NULL; auxV=auxV->next) {
        if (auxV->value == v_origem) {
            auxV->output_degree ++;
            newA->s = auxV;
        }
        if (auxV->value == v_destino) {
            auxV->entry_grade ++;
            newA->d = auxV;
        }
        newA->next = graph->edges;
    }
    return newA;
}

//Exemplo de print
void printGraphNotOriented(Graph *graph) {

    Vertex *auxV;
    Edge *auxE;
    printf("\n********* Vertexes ************\n");
    for (auxV = graph->vertexes; auxV!=NULL; auxV=auxV->next) {
       printf("\t %d --- (%d) \n", auxV->value, (auxV->entry_grade + auxV->output_degree));
    }
    printf("\n\n********* Edges ************\n");
    if (graph->edges == NULL) {
        printf("No edges!");
    }
    else {
        for (auxE = graph->edges; auxE!=NULL; auxE=auxE->next) {
            printf("\t (%d, %d)", auxE->s->value, auxE->d->value);
        }
    }
    printf("\n");
}

//Exemplo de print
void printGraphOriented( Graph *graph) {

    Vertex *auxV;
    Edge *auxE;

    printf("\n********* Vertexes ************\n");
    for (auxV = graph->vertexes; auxV!=NULL; auxV=auxV->next) {
        printf("\t %d s(%d) d(%d),\n", auxV->value, auxV->output_degree, auxV->entry_grade);
    }
    printf("\n\n********* Edges ************\n");
    if (graph->edges == NULL) {
        printf("No edges!");
    }
    else {
        for (auxE = graph->edges; auxE!=NULL; auxE=auxE->next) {
             printf("\t (%d, %d)", auxE->s->value, auxE->d->value);
        }
    }
    printf("\n\n********* Vertices Fonte ************\n");
    for (auxV = graph->vertexes; auxV!=NULL; auxV=auxV->next) {
        if (auxV->entry_grade == 0){
            printf("\t %d", auxV->value);
        }
    }

    printf("\n\n********* Vertices Sumidouro ************\n");
        for (auxV = graph->vertexes; auxV!=NULL; auxV=auxV->next) {
        if (auxV->output_degree == 0){
            printf("\t %d", auxV->value);
        }
    }
    printf("\n");
}


    // Buescar a Origem e o Destino na lista de Vértices. 
       //Devem ser os mesmo que estão na lista de vértices, não podem ser criados.

//Não orientado:
// -- Listar todos os vertices com os respectivos graus.

//Grafo orientado:
// -- Listar os graus de entrada e saida para cada um dos vértices.
// -- Listar todos os vértices que são sumidouro
// -- Listar todos os vértices que são fonte

Graph *newGraph(){
    Graph *new = malloc (sizeof(Graph));
    
    new->oriented = 0;
    new->edges = NULL;
    new->vertexes = NULL;
    return new;
}

int main(){

    Graph *g1 = newGraph();

    printf("O grafo eh orientado? \n 1 - sim\n 0 - nao\n");
    scanf("%d", &g1->oriented);
    printf("----\n");
    
    g1->vertexes = insertVertex(g1->vertexes, 1);
    g1->vertexes = insertVertex(g1->vertexes, 2);
    g1->vertexes = insertVertex(g1->vertexes, 3);
    g1->vertexes = insertVertex(g1->vertexes, 4);
    g1->vertexes = insertVertex(g1->vertexes, 5); 

    g1->edges = insertEdge(g1, 5, 1);
    g1->edges = insertEdge(g1, 4, 2);
    g1->edges = insertEdge(g1, 3, 1);
    g1->edges = insertEdge(g1, 4, 1);
    g1->edges = insertEdge(g1, 2, 3);
    
    if (g1->oriented == 0){
        printGraphNotOriented(g1);
    }
    else {
        printGraphOriented(g1);
    }

    return 0;
}