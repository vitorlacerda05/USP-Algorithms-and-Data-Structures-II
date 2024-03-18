/* 
    Alunos:
    Bruno Garcia de Oliveira Breda - 11212702
    Vitor Antonio de Almeida Lacerda - 12544761
*/

#ifndef ADJACENCYGRAPH_H
#define ADJACENCYGRAPH_H

#define MAX_VERTEX 100 // Define o número máximo de vértices

typedef struct{
    int vertex; // Número de vértices no grafo
    int edges; // Número de arestas no grafo
    int **adjacencyMatrix; // Matriz de adjacência para representar as conexões entre vértices
} Graph;

Graph* initGraph(int vertex);
void destroyGraph(Graph* graph);
void insertArc(Graph* graph, int v, int w);
void removeArc(Graph* graph, int v, int w);
void printGraph(Graph* graph);

#endif