class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int n  = s.length();
        int black = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '0'){
                ans += black;
            }
            else{
                black++;
            }
        }
        return ans;
    }
};