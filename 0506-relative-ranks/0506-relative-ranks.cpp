class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        int n = score.size();

        int M = 0;
        for (int x : score) {
            if (x > M) {
                M = x;
            }
        }
        std::vector<int> score_idx(M + 1, 0);
        for (int i = 0; i < n; i++) {
            score_idx[score[i]] = i + 1;
        }

        std::vector<std::string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        std::vector<std::string> rank(n, "");
        int place = 1;
        for (int i = M; i >= 0; i--) {
            if (score_idx[i] != 0) {
                int org_idx = score_idx[i] - 1;
                if (place < 4) {
                    rank[org_idx] = medals[place - 1];
                } else {
                    rank[org_idx] = std::to_string(place);
                }
                place++;
            }
        }
        return rank;
    }
};