class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // Map to store the frequency of each element
        map<int, int> mp;

        // Count the frequency of each element in the input vector
        for (auto it : nums) {
            mp[it]++;
        }

        // Create a vector of pairs from the map
        vector<pair<int, int>> v(mp.begin(), mp.end());

        // Define a custom comparator for sorting
        auto mycomp = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) {
                // If frequencies are the same, sort by element value in descending order
                return a.first > b.first;
            }
            // Otherwise, sort by frequency in ascending order
            return a.second < b.second;
        };

        // Sort the vector of pairs using the custom comparator
        sort(v.begin(), v.end(), mycomp);

        // Create the result vector to store the sorted elements
        vector<int> result;
        for (const auto& p : v) {
            // Insert each element according to its frequency
            result.insert(result.end(), p.second, p.first);
        }

        // Return the result vector
        return result;
    }
};