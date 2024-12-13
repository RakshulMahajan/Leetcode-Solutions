class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long int ans = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int i =0, n = nums.size();
        i = 0;
        while(i<n){
            pq.push({nums[i],i});
            i++;
        }
        vector<int> v(n,1);
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            if(v[p.second]){
                ans += p.first;
                if(p.second-1>=0){
                    v[p.second-1] = 0;
                }
                if(p.second+1<n){
                    v[p.second+1] = 0;
                }
            }
        }
        return ans;
    }
};