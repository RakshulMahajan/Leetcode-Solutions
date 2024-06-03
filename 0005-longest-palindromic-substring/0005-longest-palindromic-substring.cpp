class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.size();
        int reslen=0;
        string res="";
        for(int i=0;i<n;i++){

            // od length substring
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l + 1> reslen){
                    reslen=r-l+1;
                    res = s.substr(l, r - l + 1);
                }
                l--;
                r++;

            }

            // even length
             l=i, r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l + 1> reslen){
                    reslen=r-l+1;
                    res = s.substr(l, r - l + 1);
                }
                l--;
                r++;

            }
        }
        return res;

        
    }
};