class Solution {
public:
    int josephus(int n, int k) {
        int ans = 0;  // 0-based indexing

        for (int i = 1; i <= n; i++) {
            ans = (ans + k) % i;
        }

        return ans + 1; // convert to 1-based
    }
};

