class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // Step 1: Construct adjacency list
        vector<vector<int>> g(n+1);
        for(auto &e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        // Step 2: Color array for bipartite check
        vector<int> color(n+1, 0);

        // Step 3: Bipartite check with BFS
        auto bipBfs = [&](int start) {
            queue<int> q;
            q.push(start);
            color[start] = 1;
            vector<int> comp;

            while(!q.empty()){
                int u = q.front();
                q.pop();
                comp.push_back(u);
                for(int v : g[u]){
                    if(!color[v]){
                        color[v] = -color[u];  // Alternate coloring
                        q.push(v);
                    } else if(color[v] == color[u]) {
                        return vector<int>();  // Not bipartite
                    }
                }
            }
            return comp;
        };

        int ans = 0;

        // Step 4: Process each component
        for(int i = 1; i <= n; i++) {
            if (!color[i]) {
                auto comp = bipBfs(i);
                if (comp.empty()) return -1;  // Not bipartite

                int best = 0;

                // Step 5: Find maximum BFS depth in the component
                for(auto &x: comp) {
                    vector<int> dist(n+1, -1);
                    dist[x] = 0;
                    queue<int> q;
                    q.push(x);

                    while(!q.empty()){
                        int u = q.front();
                        q.pop();
                        for(int v : g[u]){
                            if (dist[v] < 0) {
                                dist[v] = dist[u] + 1;
                                q.push(v);
                            }
                        }
                    }

                    // Compute max depth in the component
                    int layers = 0;
                    for(auto &cnode : comp) 
                        if (dist[cnode] >= 0) 
                            layers = max(layers, dist[cnode]);

                    best = max(best, layers + 1);
                }
                ans += best;
            }
        }
        return ans;
    }
};