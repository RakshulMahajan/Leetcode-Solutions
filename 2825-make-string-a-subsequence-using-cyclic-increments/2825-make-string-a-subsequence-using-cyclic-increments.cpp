class Solution {
public:

    bool canMakeSubsequence(string str1, string str2) {
        
        int n1=str1.size(); 
        int n2=str2.size();
        int i=0, j=0;
        
        while(i<n1 and j<n2){
            if(str1[i]==str2[j] or str1[i]+1==str2[j]){
                i++;
                j++;
            }
            else if(str1[i]=='z' and str2[j]=='a'){
                i++;
                j++;
            }
            else i++;
        }
        
        if(j==n2) return true;
        return false;
    }
};
