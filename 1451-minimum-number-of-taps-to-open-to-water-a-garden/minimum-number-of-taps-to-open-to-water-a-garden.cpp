class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> reach(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);

            reach[left] = max(reach[left], right);
        }

        int taps = 0;
        int curEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n; i++) {
            farthest = max(farthest, reach[i]);

            if (farthest <= i)
                return -1;

            if (i == curEnd) {
                taps++;
                curEnd = farthest;
            }
        }

        return taps;
    }
};