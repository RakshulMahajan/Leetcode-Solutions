class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = string(nums.size(), '0');  // Start with "000...0"
        
        if(find(nums.begin(), nums.end(), ans) == nums.end()) return ans;  // Check if it already works

        for(int i = 0; i < nums.size(); i++) { 
            ans[i] = '1';  // Try flipping one bit at a time
            if(find(nums.begin(), nums.end(), ans) == nums.end()) 
                return ans;  
            ans[i] = '0';  // Revert back if needed
        }
        return ans;  // Fallback case
    }
};