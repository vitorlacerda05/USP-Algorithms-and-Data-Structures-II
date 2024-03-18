/* 
    Alunos:
    Bruno Garcia de Oliveira Breda - 11212702
    Vitor Antonio de Almeida Lacerda - 12544761
*/

#include "adjacencygraph.h"

#include <stdio.h>
#include <stdlib.h>

//Função para iniciar o Grafo
Graph* initGraph(int vertex){
    Graph* graph = (Graph*)malloc(sizeof(Graph)); // Aloca memória para a estrutura do grafo
    graph->vertex = vertex; // Define o número de vértices
    graph->edges = 0; // Inicializa o número de arestas como zero

    // Aloca memória para a matriz de adjacência
    graph->adjacencyMatrix = (int**)malloc(vertex * sizeof(int*));

    // Inicializa cada linha da matriz de adjacência
    for (int i = 0; i < vertex; i++){
        graph->adjacencyMatrix[i] = (int*)calloc(vertex, sizeof(int));
    }

    return graph; // Retorna o ponteiro para o grafo inicializado
}

// Função para liberar a memória alocada para o grafo
void destroyGraph(Graph* graph){
    for (int i = 0; i < graph->vertex; i++) {
        free(graph->adjacencyMatrix[i]); // Libera a memória de cada linha da matriz de adjacência
    }

    free(graph->adjacencyMatrix); // Libera a memória da matriz de adjacência
    free(graph); // Libera a memória da estrutura do grafo
}

// Função para inserir uma aresta entre dois vértices
void insertArc(Graph* graph, int v, int w){
    if (v >= 0 && v < graph->vertex && w >= 0 && w < graph->vertex){
        if (graph->adjacencyMatrix[v][w] == 0) { // Verifica se a aresta não existe
            graph->adjacencyMatrix[v][w] = 1; // Insere a aresta
            graph->edges++; // Incrementa o número de arestas
        }
    }
}

// Função para remover uma aresta entre dois vértices
void removeArc(Graph* graph, int v, int w) {
    if (v >= 0 && v < graph->vertex && w >= 0 && w < graph->vertex) {
        if (graph->adjacencyMatrix[v][w] == 1) { // Verifica se a aresta existe
            graph->adjacencyMatrix[v][w] = 0; // Remove a aresta
            graph->edges--; // Decrementa o número de arestas
        }
    }
}

// Função para imprimir o grafo
void printGraph(Graph* graph) {
    printf("Total of vertices: %d, total of arcs: %d\n", graph->vertex, (graph->edges/2)); // Imprime o número de vértices e arestas
    for (int i = 0; i < graph->vertex; i++) {
        printf("Vertices %d, arcs:", i); // Imprime o número do vértice

        int firstArcPrinted = 0; // Variável para controlar a impressão da vírgula

        // Itera sobre a linha da matriz de adjacência para encontrar as arestas do vértice atual
        for (int j = 0; j < graph->vertex; j++) {
            if (graph->adjacencyMatrix[i][j] == 1) { // Verifica se há uma aresta
                if (firstArcPrinted) {
                    printf(","); // Imprime vírgula se não for a primeira aresta
                }
                printf(" %d", j); // Imprime o vértice conectado
                firstArcPrinted = 1; // Define que a primeira aresta foi impressa
            }
        }
        printf("\n"); // Quebra de linha após imprimir todas as arestas do vértice
    }
}