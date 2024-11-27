class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Step 1: Initialize the graph with the given nodes
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        // Step 2: Function to compute shortest distances using BFS
        auto bfsShortestPath = [&](unordered_map<int, vector<int>>& graph, int n) {
            vector<int> dist(n, INT_MAX);
            queue<int> q;
            
            dist[0] = 0;
            q.push(0);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (dist[node] + 1 < dist[neighbor]) {
                        dist[neighbor] = dist[node] + 1;
                        q.push(neighbor);
                    }
                }
            }

            return dist[n - 1]; // Return the shortest path to the last node
        };

        // Step 3: Iterate through queries and compute shortest paths
        vector<int> results;

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            // Add the new edge to the graph
            adj[u].push_back(v);

            // Compute the shortest path from 0 to n-1
            int shortestPath = bfsShortestPath(adj, n);
            results.push_back(shortestPath);
        }

        return results;
    }
};