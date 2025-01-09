class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int n = words.size();
        int preflen = pref.length();

        for(auto ele: words){
            if(ele.substr(0, preflen) == pref){
                ans++;
            }
        }
        return ans;
    }
};