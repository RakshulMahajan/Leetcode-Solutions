class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size(), cols = box[0].size();
        vector<vector<char>> result(cols, vector<char>(rows, '.')); // Initialize result matrix
        
        // Process each row of the box
        for (int i = 0; i < rows; i++) {
            int emptyPosition = cols - 1; // Track the lowest position for stones
            for (int j = cols - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    // Obstacle: place it in the result and reset the empty position
                    result[j][rows - i - 1] = '*';
                    emptyPosition = j - 1;
                } else if (box[i][j] == '#') {
                    // Stone: move it to the lowest available position
                    result[emptyPosition][rows - i - 1] = '#';
                    emptyPosition--;
                }
            }
        }
        
        return result;
    }
};