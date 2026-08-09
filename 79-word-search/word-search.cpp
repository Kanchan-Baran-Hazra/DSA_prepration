class Solution {
public:
    static bool helper(vector<vector<char>>& board, string& word,
                       int i, int j, int ptr, int n, int m,
                       vector<vector<bool>>& marker) {

        if(ptr >= word.size())
            return true;

        if(i < 0 || j < 0 || i >= n || j >= m ||
           marker[i][j] == true)
            return false;

        // Check character first
        if(board[i][j] != word[ptr])
            return false;

        // Mark visited
        marker[i][j] = true;

        bool p = helper(board, word, i + 1, j, ptr + 1, n, m, marker);
        bool q = helper(board, word, i - 1, j, ptr + 1, n, m, marker);
        bool r = helper(board, word, i, j + 1, ptr + 1, n, m, marker);
        bool s = helper(board, word, i, j - 1, ptr + 1, n, m, marker);

        // Backtrack
        marker[i][j] = false;

        return p || q || r || s;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(board[i][j] == word[0]) {

                    vector<vector<bool>> marker(
                        n, vector<bool>(m, false)
                    );

                    if(helper(board, word, i, j, 0, n, m, marker))
                        return true;
                }
            }
        }

        return false;
    }
};