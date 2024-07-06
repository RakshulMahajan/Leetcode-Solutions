class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long int sum = 0;
        for (auto num : chalk)
            sum += num;

        k %= sum;
        int i;
        for (i=0; i<n; i++)
        {
            if (k % chalk[i] == k)
                break;
            else
                k -= chalk[i];
        }

        return i;
    }
};