class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        int n = s.size();
        vector<int> v(3, 0);
        for(int i = 0; i < n; i++) v[s[i]-'a'] += 1;

        if(v[0] < k || v[1] < k || v[2] < k) return -1;

        int reg = 0, j = 0;
        vector<int> count(3, 0);

        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            
            while(count[0] > v[0] - k || count[1] > v[1] - k || count[2] > v[2] - k) {
                count[s[j] - 'a']--;
                j++;
            }

            reg = max(reg, i - j + 1);
        }

        return n - reg;
    }
};
