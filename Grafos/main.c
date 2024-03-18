/* 
    Alunos:
    Bruno Garcia de Oliveira Breda - 11212702
    Vitor Antonio de Almeida Lacerda - 12544761
*/

#include <stdio.h>
#include "lib/adjacencygraph.h"

int main() {
    int vertex;
    scanf("%d", &vertex); // Lê o número de vértices do usuário

    Graph* graph = initGraph(vertex); // In icializa o grafo com o número de vértices fornecido

    int v, w;
    for (int i = 0; i <= vertex; i++) { // Loop para ler as arestas do usuário
        scanf("%d %d", &v, &w); // Lê os vértices que formam a aresta

        // Verifica se os vértices estão dentro do intervalo válido
        if (v >= 0 && v < vertex && w >= 0 && w < vertex) {
            insertArc(graph, v, w); // Insere a aresta no grafo
            insertArc(graph, w, v); // Insere a aresta reversa (grafo não direcionado)
        }
    }
    
    printGraph(graph); // Imprime o grafo
    destroyGraph(graph); // Libera a memória alocada para o grafo    

    return 0;
}