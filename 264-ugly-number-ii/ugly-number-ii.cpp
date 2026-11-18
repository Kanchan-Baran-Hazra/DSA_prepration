class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1; // 1st ugly number is 1
        
        // Pointers for multiples of 2, 3, and 5
        int p2 = 0, p3 = 0, p5 = 0; 
        
        for (int i = 1; i < n; i++) {
            int next2 = dp[p2] * 2;
            int next3 = dp[p3] * 3;
            int next5 = dp[p5] * 5;
            
            // Pick the smallest next ugly number
            dp[i] = min({next2, next3, next5});
            
            // Advance pointer(s) that matched to avoid duplicates (e.g., 2*3 and 3*2)
            if (dp[i] == next2) p2++;
            if (dp[i] == next3) p3++;
            if (dp[i] == next5) p5++;
        }
        
        return dp[n - 1];
    }
};