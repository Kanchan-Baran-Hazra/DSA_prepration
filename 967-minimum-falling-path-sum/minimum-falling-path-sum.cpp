class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Start from the second-to-last row and move upwards to row 0
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                // Get the value directly below (st)
                int down = matrix[i + 1][j];
                
                // Get down-left (lc), checking boundary
                int downLeft = (j > 0) ? matrix[i + 1][j - 1] : 1e9;
                
                // Get down-right (rc), checking boundary
                int downRight = (j < m - 1) ? matrix[i + 1][j + 1] : 1e9;
                
                // Update current cell with its value + minimum of the 3 choices below
                matrix[i][j] += min({down, downLeft, downRight});
            }
        }
        
        // The answer is the minimum value in the first row
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, matrix[0][j]);
        }
        
        return mini;
    }
};