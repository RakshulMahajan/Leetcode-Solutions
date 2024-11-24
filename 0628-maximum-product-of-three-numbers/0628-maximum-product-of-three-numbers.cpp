class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int l = nums.size(); 
        sort(nums.begin(), nums.end()); 
        int withNeg = nums[0] * nums[1] * nums[l-1]; 
        int withoutNeg = nums[l-1] * nums[l-2] * nums[l-3]; 
        return max(withNeg, withoutNeg); 
    }
};