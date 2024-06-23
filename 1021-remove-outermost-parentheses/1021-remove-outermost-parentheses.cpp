class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int cnt = 0;
        for (char chr : s)
            if (chr == '(')
                if (!cnt)
                    cnt++;
                else {
                    ans += '(';
                    cnt++;
                }
            else if (cnt > 1) {
                ans += ')';
                cnt--;
            } else
                cnt--;
        return ans;
    }
};