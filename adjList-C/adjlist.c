#include <stdio.h>
#include <stdlib.h>

#define Vertex int
typedef struct node *Link; // Link é ponteiro para estrutura tipo node
typedef struct graph *Digraph;
#define Graph Digraph

// Estrutura de nó
struct node {
  Vertex w; // Vértice
  Link next; // Ponteiro para o próximo nó
  int weight; // Peso da aresta
};

// Struct do Grafo
struct graph {
  int V; // Quantidade de vértices
  int A; // Quantidade de arestas (inicial = 0)
  Link *adj; // Ponteiro para o grafo 
};

// Inicializar o grafo
// Criar quantidade de ponteiros = vertices do tipo listaAdj que apontam para NULL
Graph initGraph(int n) {
  Graph G = (Graph)malloc(sizeof(*G));
  G->V = n;
  G->A = 0;
  G->adj = (Link *)malloc(n * sizeof(Link));
  for (int i; i < n; i++) {
    G->adj[i] = NULL; // Lista de tamanho = vertices. Cada elemento é um Node, com Link que aponta para Null
  }
  return G;
}

// Destruir o grafo
void destroyGraph(Graph G) {
  if (G != NULL) {
    for (int i; i < G->V; i++) {
      free(G->adj[i]); // Free em cada elemento da array
    }
    free(G->adj); // Free no ponteiro que apontava para o grafo
    free(G); // Free no struct G
  }
}

// Novo arco
Link newArc(Vertex w, Link next) {
  Link anode = (Link)malloc(sizeof(*anode));
  anode->w = w; // Novo vértice w
  anode->next = next; // Ponteiro do vertice w aponta para Null
  return anode;
}

// Insere novo arco na lista[vertice] do grafo
void insertArc(Graph G, Vertex v, Vertex w) {
  // verificar se o arco ja existe
  for (Link a = G->adj[v]; a != NULL; a = a->next) { //percorre todos vertices
    if (a->w == w) {
      return;
    }
  }
  G->adj[v] = newArc(w, G->adj[v]); // Crio vertice w no vertice V
  G->A++; // Somo arestas
}

// Por que é Grafo
void insertEdge(Graph G, Vertex v, Vertex w) {
  insertArc(G, v, w);
  insertArc(G, w, v); // Muda de digrafo pra grafo
}

void removeArc(Graph G, Vertex v, Vertex w) {
  if (v > G->V) {
    return;
  }
  Link prev = G->adj[v];
  for (Link p = G->adj[v]; p != NULL; p = p->next) { // Percorro toda lista encadeada de v
    if (p->w == w) { // Removo w
      G->A--;
      if (G->adj[v] == p) {
        G->adj[v] = p->next;
      } else {
        prev->next = p->next;
      }
      free(p);
      return;
    } else {
      prev = p;
    }
  }
}

void removeEgde(Graph G, Vertex v, Vertex w) { // Removo nos dois por que é grafo
  removeArc(G, v, w);
  removeArc(G, w, v);
}

int contaGraus(Graph G, Vertex v) {
  int graus = 0;
  if (v < 0 || v >= G->V) {
    return printf("Não foi possível contar os graus");
  }
  for (Link a = G->adj[v]; a != NULL; a = a->next){
    graus += 1;
  } 
/* PARA DÍGRAFO:

  int i = 0
  for (i; G->V; i++){
    for (Link a = G->adj[i]; a != NULL; a = a->next){
    if (i == v) graus++;
    if (a->w == v) grau++
  } 

*/

  return graus;
}

void printGraph(Graph G) { // Print do grafo
  printf("Graph, %d vertex and %d arcs\n", G->V, G->A);
  for (int i = 0; i < G->V; i++) {
    printf("Vertex %d: ", i);
    for (Link p = G->adj[i]; p != NULL; p = p->next) {
      printf(" %d > %d / ", i, p->w);
    }
    printf("\n");
  }
}

int main(void) {
  int n, x, y;
  Graph G;
  if (scanf("%d\n", &n) == 1) {
    G = initGraph(n);
    while (scanf("%d %d\n", &x, &y) != EOF) {
      insertEdge(G, x, y);
    }
  }
  printf("printGraph\n");
  printGraph(G);
  printf("printGraph after remove\n");
  printf("%d", contaGraus(G, 1));
  printGraph(G);
  return 0;
}