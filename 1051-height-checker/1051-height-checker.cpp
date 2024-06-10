class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> dupli;
        int ans = 0;
        for(int i =0; i<heights.size(); i++)
        {
            dupli.push_back(heights[i]);
        }
        
        sort(dupli.begin(), dupli.end());
        for(int i =0; i<heights.size(); i++)
        {
            if(heights[i] != dupli[i]){
                ans++;
            }
        }
        return ans;
        
    }
};