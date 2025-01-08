class Solution {
public:

    bool isPrefixAndSuffix(string str1, string str2){
        if(str1.length() > str2.length()){
            return false;
        }
        int n1 = str1.size(), n2 = str2.size();
        return str2.substr(0, n1) == str1 && str2.substr(n2 - n1) == str1;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(isPrefixAndSuffix(words[i], words[j])){
                    ans++;
                }
            }
           

        }
        return ans;

    }
};