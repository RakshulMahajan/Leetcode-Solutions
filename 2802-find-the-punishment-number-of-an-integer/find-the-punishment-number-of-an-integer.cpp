class Solution {
public:
    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (canPartition(to_string(i * i), 0, i)) {
                sum += (i * i);
            }
        }
        return sum;
    }

    bool canPartition(string num, int index, int target) {
        if (index == num.length()) return target == 0;

        int sum = 0;
        for (int i = index; i < num.length(); i++) {
            sum = sum * 10 + (num[i] - '0');
            if (sum > target) break;
            if (canPartition(num, i + 1, target - sum)) return true;
        }
        return false;
    }
};