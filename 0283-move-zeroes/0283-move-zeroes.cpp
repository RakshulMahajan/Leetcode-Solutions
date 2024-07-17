class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    
        vector<int>numbers;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) numbers.push_back(i);
        }
        for(int i=0;i<numbers.size();i++){
            nums[i]=nums[numbers[i]];
        }
        for(int i=numbers.size();i<nums.size();i++){
            nums[i]=0;
        }
    }
};