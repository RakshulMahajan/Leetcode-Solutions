class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        long long sum = 0;
        int st = 0;
        int e = n - 1;
        int target = skill[st] + skill[e];

        while (st < e) {
            if (skill[st] + skill[e] != target) {
                return -1;
            }
            sum += skill[st] * skill[e];
            st++;
            e--;
        }

        return sum;
    }
};