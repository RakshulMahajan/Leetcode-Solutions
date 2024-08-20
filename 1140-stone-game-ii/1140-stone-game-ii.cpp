class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        for (int i = piles.size() - 2; i >= 0; i--)
            piles[i] += piles[i + 1];
        return solve(1, 0, piles);
    }
private:
    int dp[101][101] = {};
    int solve(int m, int index, vector<int>& piles){
        if (index == piles.size()) return 0;
        else if (index + 2 * m >= piles.size()) return piles[index];
        else if (dp[m][index]) return dp[m][index];
        int res = 0, take = 0;
        for (int x = 1; x <= 2 * m && x + index < piles.size(); x++){
            take = piles[index] - piles[index + x];
            res = max(res, take + piles[index + x] - solve(max(m, x), index + x, piles));
        }
        return dp[m][index] = res;
    }
};