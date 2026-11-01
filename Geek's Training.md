## 01. Geek's Training

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/geeks-training/1)

### Problem Description

**Task:** Geek is attending a training program for n days. Each day he must perform exactly one of three activities: Running, Fighting, or Learning. Each activity earns a certain number of merit points, which can differ from day to day. To improve all his skills, Geek cannot perform the same activity on two consecutive days.Given a 2D matrix mat[][], where for the i-th day:mat[i][0] is the merit points for Runningmat[i][1] is the merit points for Fightingmat[i][2] is the merit points for LearningReturn the maximum total merit points Geek can earn over the n days.Example:Input: mat[][] = [[8, 7, 1], [9, 2, 1]]

#### Examples

##### Example 1

- **Output:**
```text
6
```
- **Explanation:** With only one day there is no consecutive-day restriction, so Geek simply picks the best activity, Learning, and earns 6 points.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (2)

#### Solution 1 (C++)

- **Submitted:** 2026-11-01 14:53:45
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
    int helper(int n,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
        int maxi=0;
        if(n==0){
            for(int i=0;i<mat[0].size();i++){
                if(i!=j){
                    maxi=max(maxi,mat[n][i]);
                }
            }
            return maxi;
        }
        if(dp[n][j]!=-1) return dp[n][j];
        
        for(int i=0;i<mat[0].size();i++){
            if(i!=j){
                maxi=max(maxi,helper(n-1,i,mat,dp)+mat[n][i]);
            }
        }
        return dp[n][j]=maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return helper(n-1,3,mat,dp);
    }
};
```

#### Solution 2 (C++)

- **Submitted:** 2026-11-01 10:59:13
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
    int helper(int n,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
        int maxi=0;
        if(n==0){
            for(int i=0;i<mat[0].size();i++){
                if(i!=j){
                    maxi=max(maxi,mat[n][i]);
                }
            }
            return maxi;
        }
        if(dp[n][j]!=-1) return dp[n][j];
        
        for(int i=0;i<mat[0].size();i++){
            if(i!=j){
                maxi=max(maxi,helper(n-1,i,mat,dp)+mat[n][i]);
            }
        }
        return dp[n][j]=maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return helper(n-1,3,mat,dp);
    }
};
```

*Generated on: 11/1/2026, 2:54:57 PM*