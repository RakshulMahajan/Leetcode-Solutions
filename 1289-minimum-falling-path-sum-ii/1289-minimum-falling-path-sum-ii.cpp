class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            int mini=1e8;
            for(int j=0;j<n;j++){
               if(j!=i){
                mini=min(mini,grid[0][j]);
               }
            }
            dp[0][i]=mini;
        }
        for(int day=1;day<n;day++){
            for(int last=0;last<=n;last++){
                int mini=1e8;
                for(int curr=0;curr<n;curr++){
                   if(curr!=last){
                    mini=min(mini,grid[day][curr]+dp[day-1][curr]);
                   }
                }
                dp[day][last]=mini;
            }
        }
        return dp[n-1][n];
    }
};