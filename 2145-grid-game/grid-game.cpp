class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> topPrefix(n+1,0),bottomPrefix(n+1,0);
        // calculate prefix sum for each row.
        for(int i = 0; i < n ; i++){
            topPrefix[i+1] = topPrefix[i] + grid[0][i];
            bottomPrefix[i+1] = bottomPrefix[i] + grid[1][i];
        }

        long long result = LLONG_MAX;
        for(int i = 0; i < n;i++){
            long long top_remaining = topPrefix[n] - topPrefix[i+1];// if player1 switches to bottom row at index i
            long long bottom_remaining = bottomPrefix[i];

            // Local Maximization
            long long player2score = max(top_remaining,bottom_remaining);// player 2 has to maximze from either top path or bottom one

            // Global Maximization
            result = min(result,player2score);//player 1 must give player2 the minimum possible points by minimizing the max path of player 2
        }
        return result;
    }
};