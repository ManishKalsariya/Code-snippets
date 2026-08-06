// kahn's algorithm.cpp
#include <bits/stdc++.h>
using namespace std;

void calculateIndegree(vector<vector<int>>& adj, vector<int>& indegree) {
    for (int u = 0; u < adj.size(); u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }
}

void kahnsAlgorithm(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for (auto& it : edges) {
        adj[it[0]].push_back(it[1]);
    }

    vector<int> indegree(V, 0);
    calculateIndegree(adj, indegree);

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (topoOrder.size() != V) {
        cout << "The graph has a cycle. Topological sorting is not possible." << endl;
    } else {
        cout << "Topological Order: ";
        for (int node : topoOrder) {
            cout << node << " ";
        }
        cout << endl;
    }

    
}

