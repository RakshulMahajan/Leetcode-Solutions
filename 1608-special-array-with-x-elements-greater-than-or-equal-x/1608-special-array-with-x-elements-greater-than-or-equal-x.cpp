class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(rbegin(nums),rend(nums));
        int n = size(nums);
        for(int i=0;i<n;i++){
            if(nums[i]>=(i+1)){
                if(i==n-1 || nums[i+1]<i+1)return i+1;
            }
        }
        return -1;
    }
};