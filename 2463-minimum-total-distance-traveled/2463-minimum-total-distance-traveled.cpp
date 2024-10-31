class Solution {
public:

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        int n = robot.size();
        int m = factory.size();

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

      vector<vector<long long>> ans(n+1, vector<long long>(m+1));

      for(int i = 0; i<n; i++)
      {
        ans[i][m] = LLONG_MAX;
      }

      for(int j = m-1; j>=0; j--)
      {
        long long sum = 0;

        deque<pair<int, long long>> q;

        q.push_back({n, 0});

        for(int i = n-1; i>=0; i--)
        {
            sum += abs(robot[i] - factory[j][0]);

            while( !q.empty() && q.front().first > i+ factory[j][1])
            {
                q.pop_front();
            }

            while( !q.empty() && q.back().second >=  ans[i][j+1] - sum)
            {
                q.pop_back();
            }

           q.push_back({i , ans[i][j+1] - sum});
           ans[i][j] = q.front().second + sum;
        }
      }
      
     return ans[0][0];

    }
};