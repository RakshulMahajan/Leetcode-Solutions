class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size() - 1, nums);
        return nums;
    }

private:
    void mergeSort(int left, int right, vector<int>& nums) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(left, mid, nums);
        mergeSort(mid + 1, right, nums);
        merge(left, mid, right, nums);
    }

    void merge(int left, int mid, int right, vector<int>& nums) {
        vector<int> sortedList;
        int indx1 = left, indx2 = mid + 1;
        while (indx1 < mid + 1 && indx2 < right + 1) {
            if (nums[indx1] <= nums[indx2]) {
                sortedList.push_back(nums[indx1++]);
            } else {
                sortedList.push_back(nums[indx2++]);
            }
        }
        while (indx1 < mid + 1) {
            sortedList.push_back(nums[indx1++]);
        }
        while (indx2 < right + 1) {
            sortedList.push_back(nums[indx2++]);
        }
        int indx = left;
        for (auto num : sortedList) {
            nums[indx++] = num;
        }
    }
};