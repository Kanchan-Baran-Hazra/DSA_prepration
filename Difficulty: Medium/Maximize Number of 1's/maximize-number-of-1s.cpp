class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int i = 0, j = 0;
        int ans = 0;

        while (j < arr.size()) {
            if (arr[j] == 0) k--;

            while (k < 0) {
                if (arr[i] == 0) k++;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

