class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        for(long i = 1; i<=n; i=i*2) n ^=i;
        return n;
    }
};