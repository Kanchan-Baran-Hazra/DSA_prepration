class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0;
        int j = n - 1;

        // Find possible row
        while (i <= j) {
            int mid = i + (j - i) / 2;

            if (target >= matrix[mid][0] &&
                target <= matrix[mid][m - 1]) {

                // Binary search inside this row
                int l = 0;
                int r = m - 1;

                while (l <= r) {
                    int mid2 = l + (r - l) / 2;

                    if (matrix[mid][mid2] == target)
                        return true;
                    else if (matrix[mid][mid2] < target)
                        l = mid2 + 1;
                    else
                        r = mid2 - 1;
                }

                return false;
            }
            else if (matrix[mid][m - 1] < target) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }

        return false;
    }
};