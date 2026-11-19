class Solution {
    int helper(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& memo) {
        if (row == grid.size() - 1) return grid[row][col];
        if (memo[row][col] != 1e9) return memo[row][col];

        int mini = 1e9;
        for (int nextCol = 0; nextCol < grid[0].size(); nextCol++) {
            if (nextCol == col) continue; // Cannot pick the same column
            mini = min(mini, helper(grid, row + 1, nextCol, memo));
        }
        return memo[row][col] = mini + grid[row][col];
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> memo(n, vector<int>(n, 1e9));
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, helper(grid, 0, i, memo));
        }
        return mini;
    }
};