#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

//Bruno Garcia de Oliveira Breda - 11212702
//Vitor Antônio de Almeida Lacerda - 12544761
class Arc{
public:
    int s;
    int d;
    int w;
    Arc(int s, int d, int w) : s(s), d(d), w(w) {}
};

class Digraph{
private:
    std::vector<std::vector<int>> adjMatrix;
    int size;

public:
    Digraph(int size) : size(size){
        adjMatrix.resize(size, std::vector<int>(size, std::numeric_limits<int>::max()));
        for (int i = 0; i < size; ++i) {
            adjMatrix[i][i] = 0;
        }
    }

    void insertArc(const Arc& arc){
        adjMatrix[arc.s][arc.d] = arc.w;
    }

    void removeArc(const Arc& arc){
        adjMatrix[arc.s][arc.d] = 0;
    }

    std::vector<int> dijkstra(int s, std::vector<int>& prev){
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        std::vector<int> distance(size, std::numeric_limits<int>::max());
        prev.assign(size, -1);

        pq.push(std::make_pair(0, s));
        distance[s] = 0;

        while (!pq.empty()){
            int u = pq.top().second;
            pq.pop();

            for (int v = 0; v < size; ++v){
                if (adjMatrix[u][v] != std::numeric_limits<int>::max()){
                    int alt = distance[u] + adjMatrix[u][v];
                    if (alt < distance[v]){
                        distance[v] = alt;
                        prev[v] = u;
                        pq.push(std::make_pair(distance[v], v));
                    }
                }
            }
        }

        return distance;
    }
};

void printPath(int v, const std::vector<int>& prev){
    if (prev[v] == -1){
        std::cout << v;
        return;
    }

    printPath(prev[v], prev);
    std::cout << " -> " << v;
}

int main(){
    int v;
    std::cin >> v;
    Digraph digraph(v);
    int s, d, w;

    while (std::cin >> s >> d >> w){
        Arc arc(s, d, w);
        digraph.insertArc(arc);

    }

    for (int i = 0; i < v; ++i){
        std::vector<int> prev;
        std::vector<int> distance = digraph.dijkstra(i, prev);
        std::cout << "Node " << i << ":\n";
        for (int d = 0; d < v; ++d){

            std::cout << "Distance from " << i << " to " << d << " = ";
            if (distance[d] == std::numeric_limits<int>::max()){
                
                std::cout << "infinity\n";

            } else{
                
                std::cout << distance[d] << "\n";

                if (distance[d] > 0){
                    std::cout << "Path: ";
                    printPath(d, prev);
                    std::cout << "\n";
                }
            }
        }
        if (i < v - 1){
            std::cout << "\n";
        }
    }

    return 0;
}