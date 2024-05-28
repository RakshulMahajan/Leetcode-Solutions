class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(); // Size of the input array
        long long sum = 0; // Long long to avoid overflow when summing up
        int ans = n + 1; // Initialize the answer to the max possible length+1 (invalid case scenario)

        // Two pointers, 'i' is the end of the current subarray
        // 'j' is the start of the current subarray
        for (int i = 0, j = 0; i < n; ++i) {
            sum += nums[i]; // Increase the sum by the current element

            // While sum is not smaller than the target and start pointer 'j' has not reached the end
            while (j < n && sum >= target) {
                ans = min(ans, i - j + 1); // Update the answer with the new minimum length
                sum -= nums[j++]; // Subtract the first element of the subarray and move 'j' right
            }
        }

        // If 'ans' didn't change, no valid subarray was found, return 0
        // Otherwise, return the length of the shortest subarray
        return ans == n + 1 ? 0 : ans;
    }
};