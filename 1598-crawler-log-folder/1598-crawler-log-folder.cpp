class Solution {
public:
    int n;
    int f(int i, vector<string>& logs){
        if (i<0) return 0;
        int prev=f(i-1, logs);
        if (logs[i]=="../") return prev-(prev>0);
        if (logs[i]!="./") return 1+prev;
        return prev;
    }
    int minOperations(vector<string>& logs) {
        int n=logs.size();   
        return f(n-1, logs);
    }
};