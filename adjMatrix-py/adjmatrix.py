class Graph:

    def __init__(self, vertices):  # Método construtor
        self.arestas = 0
        self.vertices = vertices
        # Compreensão de lista para criar matriz e inicializar com 0
        self.matrix = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def destroyGraph(self):
        self.arestas = 0
        self.vertices = 0

        # Em C eu iria rodar a matriz e liberar a memória de cada linha da matriz (free), e dar free para a self.matrix e para a struct.
        self.matrix = None

    def insertArc(self, v, w):
        if (v >= 0 and v < (self.vertices)) and (w >= 0 and w < (self.vertices)):  # Verificação
            if self.matrix[v][w] == 0:
                self.matrix[v][w] = 1
                self.matrix[w][v] = 1  # Por que é grafo não direcionado
                self.arestas += 1  # Soma 1 aresta
            else:
                print("Insira arestas no conjunto de vertices existentes")
        else:
            print("A aresta já foi adicionado")

    def removeArc(self, v, w):
        if (v >= 0 and v < (self.vertices)) and (w >= 0 and w < (self.vertices)):  # Verificação
            if self.matrix[v][w] == 1:
                self.matrix[v][w] = 0
                self.matrix[w][v] = 0  # Por que é grafo não direcionado
                self.arestas -= 1  # Remove 1 aresta
            else:
                print("Remova arestas no conjunto de vertices existentes")
        else:
            print("Já não possui arestas")

    def printGraph(self):
        print("\nQuantidade de vértices:", self.vertices)
        print("Quantidade de arestas:", self.arestas)
        print("\nMatriz de Adjacência:")
        print("    ", end='')
        for i in range(self.vertices):
            print(f"{(i):4}", end="")
        print()
        for i in range(self.vertices):
            print(f"{(i):2}:", end=" ")
            for j in range(self.vertices):
                print(f"{self.matrix[i][j]:4}", end="")
            print()


grafo = Graph(6)

grafo.insertArc(3, 5)
grafo.insertArc(2, 5)
grafo.insertArc(4, 3)
grafo.insertArc(1, 5)

grafo.removeArc(1, 5)

grafo.printGraph()
