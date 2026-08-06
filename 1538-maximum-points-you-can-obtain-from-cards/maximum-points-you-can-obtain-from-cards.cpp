class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int sum = 0;
        for (int x : cardPoints)
            sum += x;

        if (k == n)
            return sum;

        int len = n - k;

        int psum = 0;
        for (int i = 0; i < len; i++)
            psum += cardPoints[i];

        int ans = psum;

        int i = 0;
        for (int j = len; j < n; j++) {
            psum += cardPoints[j];
            psum -= cardPoints[i++];
            ans = min(ans, psum);
        }

        return sum - ans;
    }
};