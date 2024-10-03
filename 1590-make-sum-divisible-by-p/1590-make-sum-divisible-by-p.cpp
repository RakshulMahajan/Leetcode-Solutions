class Solution {
public:
    int minSubarray(vector<int>& A, int p) {
        
        int n=A.size(),mini=n;
         long long T=0,S=0;

        // Get Total Sum
        for(auto & x: A)
            T=(T+x)%p ;

        // If Total sum of array is Divisible by p : ans 0
        if(!T) return 0;

        unordered_map<int,int>m;
        m[0]=-1;
        for(int i=0;i<n;i++)
        {
            S+=A[i];
            
            int r=((S-T)%p +p)%p;
           if(m.find(r)!=m.end()) mini=min(mini,i-m[r]);

            m[S%p]=i;

        }
        return mini==n? -1: mini;
    }
};