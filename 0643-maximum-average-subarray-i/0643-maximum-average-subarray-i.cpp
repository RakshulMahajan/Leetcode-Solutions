class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        
        // Calculate the sum of the first `k` elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        int maxSum = sum;
        
        // Slide the window across the array
        for (int i = k; i < n; i++) {
            sum = sum - nums[i - k] + nums[i]; // Remove the leftmost and add the new element
            maxSum = max(maxSum, sum);        // Update the maximum sum
        }
        
        // Return the maximum average
        return (double)maxSum / k;
    }
};
