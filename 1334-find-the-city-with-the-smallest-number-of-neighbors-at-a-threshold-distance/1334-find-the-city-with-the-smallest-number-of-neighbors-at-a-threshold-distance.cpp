class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Initialising distance array
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }
        //Marking its weight from one city to its neighbour city
        for(auto it : edges)
        {
            int from = it[0];
            int to = it[1];
            int weight = it[2];
            dist[from][to] = weight;
            dist[to][from] = weight;
        }
        //Implementing Floyd Warshall Algorithm
        for(int thr = 0; thr < n; thr++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(dist[i][j] > dist[i][thr] + dist[thr][j])
                    {
                        dist[i][j] = dist[i][thr] + dist[thr][j];
                    }
                }
            }
        }
        int mincnt = n, city = -1;
        //Finding the no of cities can be reached from each city in the threshold distance
        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++)
            {
                if(dist[i][j] <= distanceThreshold)
                {
                    cnt++;
                }
            }
            if(mincnt >= cnt)
            {
                mincnt = cnt;
                city = i;
            }
        }
        return city;
    }
};