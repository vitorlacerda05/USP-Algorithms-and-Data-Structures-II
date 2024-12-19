/*
ALUNOS:
Vitor Antonio de Almeida Lacerda - 12544761
Bruno Garcia de Oliveira Breda - 11212702
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Estrutura de dados para representar um grafo
typedef struct {
    int vertices;       // Número de vértices no grafo
    int edges;          // Contar número de arestas no grafo. Quando conto aumento 1 a contagem
    int **adj_matrix;   // Matriz de adjacência para representar as conexões entre vértice. Ponteiro para uma matriz
} Graph;

// Função para inicializar um grafo com o número especificado de vértices
// Cria uma matriz QUADRADA
Graph* initGraph(int vertices) {
    // Aloca memória para a estrutura do grafo
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;     // Define o número de vértices
    graph->edges = 0;               // Inicialmente não há arestas no grafo

    // Aloca memória para a matriz de adjacência e inicializa com zeros
    graph->adj_matrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adj_matrix[i] = (int*)calloc(vertices, sizeof(int));
    }

    return graph;   // Retorna o grafo inicializado
}

// Função para liberar a memória alocada para o grafo
void destroyGraph(Graph* graph) {
    // Libera a memória de cada linha da matriz de adjacência
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);    // Libera a memória da matriz de adjacência
    free(graph);                // Libera a memória da estrutura do grafo
}

// Função para inserir uma aresta entre dois vértices
void insertArc(Graph* graph, int v, int w) {
    // Verifica se os vértices estão dentro do intervalo esperado
    if (v >= 0 && v < graph->vertices && w >= 0 && w < graph->vertices) {
        // Verifica se a aresta já existe na matriz de adjacência
        if (graph->adj_matrix[v][w] == 0) {
            graph->adj_matrix[v][w] = 1;   // Adiciona a aresta na matriz de adjacência
            graph->edges++;                 // Incrementa o número de arestas no grafo
        }
    }
}

// Função para remover uma aresta entre dois vértices
void removeArc(Graph* graph, int v, int w) {
    // Verifica se os vértices estão dentro do intervalo esperado
    if (v >= 0 && v < graph->vertices && w >= 0 && w < graph->vertices) {
        // Verifica se a aresta existe na matriz de adjacência
        if (graph->adj_matrix[v][w] == 1) {
            graph->adj_matrix[v][w] = 0;   // Remove a aresta da matriz de adjacência
            graph->edges--;                 // Decrementa o número de arestas no grafo
        }
    }
}

// Função para imprimir o grafo
void printGraph(Graph* graph) {
    printf("Total of vertices: %d, total of arcs: %d\n", graph->vertices, (graph->edges/2));
    // Itera sobre cada vértice
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d, arcs:", i);
        int first_arc_printed = 0;
        // Itera sobre cada aresta do vértice atual
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->adj_matrix[i][j] == 1) {
                // Se for a primeira aresta do vértice, imprime apenas o vértice de destino
                if (first_arc_printed) {
                    printf(",");
                }
                printf(" %d", j);   // Imprime o vértice de destino da aresta
                first_arc_printed = 1;   // Marca que a primeira aresta foi impressa
            }
        }
        printf("\n");   // Nova linha para o próximo vértice
    }
}

int main() {
    int vertices;
    scanf("%d", &vertices); // Lê o número de vértices

    Graph* graph = initGraph(vertices); // Inicializa o grafo com o número de vértices especificado

    int v, w;
    // Loop para inserir as arestas no grafo
    for (int i = 0; i <= vertices; i++) {
        scanf("%d %d", &v, &w); // Lê as extremidades da aresta
        // Verifica se as extremidades estão dentro do intervalo esperado
        if (v >= 0 && v < vertices && w >= 0 && w < vertices) {
            insertArc(graph, v, w); // Insere a aresta no grafo
            insertArc(graph, w, v); // Adiciona também o arco no sentido inverso
        } else {
            printf("Vértices fora do intervalo esperado. Ignorando entrada.\n");
        }
    }
    
    printGraph(graph);  // Imprime o grafo

    destroyGraph(graph); // Libera a memória alocada para o grafo

    return 0;   // Retorna 0 para indicar sucesso
}
