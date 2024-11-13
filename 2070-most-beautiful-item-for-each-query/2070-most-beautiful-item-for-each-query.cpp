class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<pair<int, int>> queryIndex; // {query, index} 
        int n = queries.size();
        //Store the queries with indices
        for(int i = 0; i < n; i++)
        {
            queryIndex.push_back({queries[i], i});
        }
        sort(queryIndex.begin(), queryIndex.end());
        vector<int> ans(n, 0);
        int maxBeauty = 0;
        int i = 0;
        int m = items.size();
        //To check out every items price as compare to the queries
        for(auto& [query, index] : queryIndex)
        {
            while(i < m && items[i][0] <= query)
            {
                maxBeauty = max(maxBeauty, items[i][1]);
                i++;
            }
            ans[index] = maxBeauty; // Store the max beauty for this query
        }
        return ans;
    }
};