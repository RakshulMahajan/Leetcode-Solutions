class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        std::priority_queue<std::pair<int, int>> pq;

        for (int i = 0; i < difficulty.size(); ++i) {
            int dif = difficulty[i];
            int prof = profit[i];
            std::pair<int, int> p = std::make_pair(prof, dif);

            pq.push(p);
        }

        std::sort(worker.begin(), worker.end(), std::greater());

        int maxProfit = 0;
        for (int i = 0; i < worker.size(); ++i) {
            int worker_difficulty = worker[i];

            while (!pq.empty() && pq.top().second > worker_difficulty) {
                pq.pop();
            }

            if (!pq.empty()) {
                maxProfit += pq.top().first;
            }
            else {
                return maxProfit;
            }
        }
        return maxProfit;
    }
};