class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size(); // Get the number of rows in the matrix
        int cols = matrix[0].size(); // Get the number of columns in the matrix
        
        vector<int> dp(cols, 0); // DP array to store the size of the largest square ending at each column
        int totalSquares = 0; // Variable to hold the total count of square submatrices
        int topLeft = 0; // Variable to store the value from the top-left diagonal cell

        // Iterate through each row of the matrix
        for (int i = 0; i < rows; i++) {
            // Iterate through each column of the current row
            for (int j = 0; j < cols; j++) {
                int currentTop = dp[j]; // Store the current value of the DP array at column j
                
                // Check if the current cell in the matrix is 1
                dp[j] = matrix[i][j] == 1 
                    ? (j == 0 // If in the first column, it can only form a 1x1 square
                        ? 1 
                        : 1 + min({dp[j], dp[j - 1], topLeft}) // Otherwise, calculate size using DP values
                       ) 
                    : 0; // If the current cell is 0, no square can end here
                
                totalSquares += dp[j]; // Add the size of the square ending at (i, j) to the total count
                
                topLeft = currentTop; // Update topLeft for the next iteration (stores previous value)
            }
        }
        
        return totalSquares; // Return the total count of squares found
    }
};