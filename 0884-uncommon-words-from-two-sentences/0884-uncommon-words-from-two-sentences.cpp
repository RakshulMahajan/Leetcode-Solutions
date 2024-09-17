class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        int n = s1.size();
        int i = 0;
        while (i < n) {
            string t = "";
            while (i < n && s1[i] != ' ') {
                t += s1[i];
                i++;
            }
            i++;
            mp[t]++;
        }
        int j = 0;
        while (j < s2.size()) {
            string t = "";
            while (j < s2.size() && s2[j] != ' ') {
                t += s2[j];
                j++;
            }
            j++;
            mp[t]++;
        }
        vector<string> v;
        for (auto it : mp)
            if (it.second == 1)
                v.push_back(it.first);

        return v;
    }
};