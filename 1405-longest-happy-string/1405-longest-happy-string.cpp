class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Priority queue (max heap) with pairs (-count, char) so that it is sorted in descending order of count
        priority_queue<pair<int, char>> pq;

        // Push the available characters into the priority queue
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string result = "";

        while (pq.size()) {
            // Pop the most frequent character
            auto [count1, char1] = pq.top();
            pq.pop();

            // Check if we can add this character without violating the "happy" condition
        if (result.size() >= 2 && result.back() == char1 && result[result.size() - 2] == char1) {
                // If adding this character results in three consecutive occurrences,
                // we need to add the second most frequent character (if possible)
            if (pq.empty()) break; // No other character available to avoid breaking the rule

                auto [count2, char2] = pq.top();
                pq.pop();

                // Add the second most frequent character
                result += char2;
                if (--count2 > 0) pq.push({count2, char2});

                // Push the original character back into the queue
                pq.push({count1, char1});
            } else {
                // Safe to add this character
                result += char1;
                if (--count1 > 0) pq.push({count1, char1});
            }
        }

        return result;
    }
};