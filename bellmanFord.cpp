// Bellman-Ford algorithm implementation in C++
//bellman-ford algorithm is used to find the shortest path from a single source vertex
// to all other vertices in a weighted graph. It can handle graphs with negative weight edges,
// unlike Dijkstra's algorithm. However, it cannot handle graphs with negative weight cycles(cycle with overall negative weight).
#include <bits/stdc++.h>
using namespace std;


class Edge{
    int v;
    int wt;
    public :
    Edge(int v, int wt){
        this->v = v;
        this->wt = wt;
    }
};

void bellManFord(int src, vector<vector<Edge>>& graph, int V){
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i = 0; i < V - 1; i++){
        for(int u = 0; u < V; u++){
            for(auto edge : graph[u]){
                int v = edge.v;
                int wt = edge.wt;
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }

    // Check for negative weight cycles
    for(int u = 0; u < V; u++){
        for(auto edge : graph[u]){
            int v = edge.v;
            int wt = edge.wt;
            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                cout << "Graph contains negative weight cycle" << endl;
                return;
            }
        }
    }

    // Print the shortest distances
    cout << "Vertex Distance from Source" << endl;
    for(int i = 0; i < V; i++){
        cout << i << "\t\t" << dist[i] << endl;
    }
}


int main() {
    int V = 5; // Number of vertices
    vector<vector<Edge>> graph(V);

    // Adding edges to the graph
    graph[0].push_back(Edge(1, -1));
    graph[0].push_back(Edge(2, 4));
    graph[1].push_back(Edge(2, 3));
    graph[1].push_back(Edge(3, 2));
    graph[1].push_back(Edge(4, 2));
    graph[3].push_back(Edge(1, 1));
    graph[3].push_back(Edge(2, 5));

    bellManFord(0, graph, V);

    return 0;
}