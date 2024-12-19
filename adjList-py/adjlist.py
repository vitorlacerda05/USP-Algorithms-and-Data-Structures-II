class Node:
    def __init__(self, vertex, weight=1):
        self.vertex = vertex
        self.weight = weight
        self.next = None


class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.edges = 0
        self.adj_list = [None for _ in range(vertices)]

    def add_arc(self, v, w, weight=1):
        new_node = Node(w, weight)
        new_node.next = self.adj_list[v]
        self.adj_list[v] = new_node
        self.edges += 1

    def remove_arc(self, v, w):
        current = self.adj_list[v]
        prev = None
        while current:
            if current.vertex == w:
                if prev:
                    prev.next = current.next
                else:
                    self.adj_list[v] = current.next
                self.edges -= 1
                return
            prev = current
            current = current.next

    def print_graph(self):
        for i in range(self.vertices):
            print(f"Vertex {i}: ", end="")
            temp = self.adj_list[i]
            while temp:
                print(f"-> {temp.vertex}({temp.weight}) ", end="")
                temp = temp.next
            print()


graph = Graph(4)  # Exemplo com 4 vértices
graph.add_arc(0, 1, 2)
graph.add_arc(0, 2, 3)
graph.add_arc(1, 3, 4)
graph.print_graph()
graph.remove_arc(0, 2)
graph.print_graph()
