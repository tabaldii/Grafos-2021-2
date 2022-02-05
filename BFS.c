
// Anderson Henrique Grosselli Tabaldi
// Matricula: 2011100008

#include <stdio.h>
#include <stdlib.h>

#define TAM 6

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
    printf("Fila -> ");
    for (aux = fila.primeiro; aux != NULL; aux = aux->next){
        printf("%d, ", aux->elemento);
    }
    printf("\n");
    printf("-------\n");
}

void BFS(int inicio, int matriz[TAM][TAM], Fila fila,  int anterior[TAM], int visitado[TAM], int distancia[TAM]) {

    int i = inicio, j;
    fila = incluiEle(fila, inicio);

    while (visitado[i] != 1) {

        visitado[i] = 1;

        printf("Visitando -> %d\n", i);
        printf("------------\n");
        printf("     vertice    |    visitado  |     valor de caminho    |   anterior    |\n");

        for(int k = 0; k < TAM; k++) {
            printf("\t%d\t|\t%d\t|\t%d\t|\t%d\t|", k, visitado[k], distancia[k], anterior[k]);
            printf("\n");
        }
        showFila(fila);

        for (j = 0; j < TAM; j++) {
                if (matriz[i][j] != 0) {
                    if (visitado[j] != 1) {
                        fila = incluiEle(fila, j);
                    }
                    distancia[j] = distancia[i] + 1;
                    anterior[j] = i;
                }
        }

        fila = removeEle(fila);
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
            //0  1  2  3  4  5
    /*0*/   { 0, 1, 0, 1, 0, 0},
    /*1*/   { 1, 0, 1, 0, 0, 0},
    /*2*/   { 0, 1, 0, 0, 0, 0},
    /*3*/   { 1, 0, 0, 0, 1, 1},
    /*4*/   { 0, 0, 0, 1, 0, 1},
    /*5*/   { 0, 0, 0, 1, 1, 0},
    };


    int anterior[TAM], visitado[TAM], distancia[TAM];
    
    for (int i = 0; i < TAM; i++) {
        anterior[i] = -1;
        visitado[i] = 0;
        distancia[i] = NULL;
    }
    
    Fila fila;
    fila.primeiro = NULL;
    fila.ultimo = NULL;

    BFS(inicio, matriz, fila, anterior, visitado, distancia);


    return 0;
}




/*
struct elemFila {
tipoElemFila info;
struct elemFila * prox;
};
typedef struct elemFila ElemFila;
struct fila {
ElemFila * ini;
ElemFila * fim;
};
Fila * fila_cria(void)
{
Fila * f = (Fila *)malloc(sizeof(Fila));
f->ini = f->fim = NULL;
return f;
}
int fila_vazia(Fila * f)
{
return (f->ini == NULL);
}
void fila_insere(Fila * f, tipoElemFila v)
{
ElemFila * n = (ElemFila *)malloc(sizeof(ElemFila));
assert(!(n == NULL)); // ou: if (n == NULL) { printf("sem memoria\n"); exit(1); }
n->info = v; // armazena informacao
n->prox = NULL; // novo no' passa a ser o ultimo
if (!fila_vazia(f)) // verifica se lista nao e’ vazia
f->fim->prox = n;
else // fila estava vazia
f->ini = n;
f->fim = n; // fila aponta para novo elemento
}
tipoElemFila fila_retira(Fila * f)
{
ElemFila * t;
tipoElemFila v;
assert(!fila_vazia(f)); // ou: if (fila_vazia(f)) {printf("Fila vazia.\n"); exit(1);}
t = f->ini;
v = t->info;
f->ini = t->prox;
if (f->ini == NULL) // verifica se fila ficou vazia
f->fim = NULL;
free(t);
return v;
}
void fila_libera(Fila * f)
{
ElemFila * q = f->ini;
ElemFila * t;
while (q != NULL)
{
t = q->prox;
free(q);
q = t;
}
free(f);
}
void fila_imprime(Fila * f)
{
ElemFila * p;
printf("Fila:\n");
if (fila_vazia(f))
 return;
for (p = f->ini; p != NULL; p = p->prox)
printf("%f ", p->info);
printf("\n");
}
*/


/*
1 for cada vértice u  V[G] – {s}
2 do cor[u] <- BRANCO
3 d[u] <- 
4 pai[u] <- NULL
5 cor[s] <- CINZA
6 d[s] <- 0
7 pai[s] <- NULL
8 Q <- 
9 ENQUEUE(Q, s) //Insere s na fila Q
10 while Q 
11 do u <- DEQUEUE(Q) //Consulta e remove o primeiro elemento da fila Q
12 for cada v <- Adj[u]
13 do if cor[v] = BRANCO
14 then cor[v] <-CINZA
15 d[v] <- d[u] + 1
16 pai[v] <- u
17 ENQUEUE (Q, v)
18 cor[u] <- PRETO
*/