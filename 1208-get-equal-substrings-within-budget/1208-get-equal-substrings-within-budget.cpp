class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int totalCost = 0;
        int startIndex = 0;
        int maxLength = 0;

        for (int endIndex = 0; endIndex < n; endIndex++) {
            // Calculate the cost of transforming the character at endIndex
            totalCost += abs(s[endIndex] - t[endIndex]);

            // Shrink the window from the left if the cost exceeds maxCost
            while (totalCost > maxCost) {
                totalCost -= abs(s[startIndex] - t[startIndex]);
                startIndex++;
            }

            // Update the maximum length of equal substring
            maxLength = max(maxLength, endIndex - startIndex + 1);
        }

        return maxLength;
    }
};