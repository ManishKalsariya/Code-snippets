//leetcode 3310 : remove methods from project :


class Solution {
public:

    void dfs(int src, vector<int>& visited, const vector<vector<int>>& adj) {
        visited[src] = 1;
        for (int neighbor : adj[src]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> visited(n, 0);
        dfs(k, visited, adj);

        for (const auto& edge : invocations) {
            int u = edge[0], v = edge[1];
            if (!visited[u] && visited[v]) {
                vector<int> ans(n);
                for (int i = 0; i < n; i++) ans[i] = i;
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};