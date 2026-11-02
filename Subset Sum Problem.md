## 01. Subset Sum Problem

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1)

### Problem Description

**Task:** Given an array of positive integers arr[] and a value sum, find if there is a subset of arr[] with sum equal to given sum. Examples:Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9Output: true

#### Examples

##### Example 1

- **Explanation:** Here there exists a subset with target sum = 9, 4+3+2 = 9.

##### Example 2

- **Input:**
```text
arr[] = [3, 34, 4, 12, 5, 2], sum = 30
```
- **Output:**
```text
trueExplanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
```
- **Explanation:** There is no subset with target sum 30.Input: arr[] = [1, 2, 3], sum = 6

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(sum*n)
- **Expected Auxiliary Space Complexity:** O(sum)

### Accepted Solutions (2)

#### Solution 1 (C++)

- **Submitted:** 2026-11-02 09:23:00
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
    bool helper(int i, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        // Base Cases
        if (sum == 0) return true;
        if (i == arr.size()) return sum == 0;

        // Check if already computed
        if (dp[i][sum] != -1) return dp[i][sum];

        // Option 1: Do not take the current element
        bool not_take = helper(i + 1, sum, arr, dp);

        // Option 2: Take the current element (if it doesn't exceed the target sum)
        bool take = false;
        if (sum >= arr[i]) {
            take = helper(i + 1, sum - arr[i], arr, dp);
        }

        // Store and return the result
        return dp[i][sum] = not_take || take;
    }

public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        // dp table of size n x (target + 1) initialized to -1
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return helper(0, target, arr, dp);
    }
};
```

#### Solution 2 (C++)

- **Submitted:** 2026-03-12 08:51:16
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    bool helper(vector<int>& arr, int sum,int i,vector<vector<int>> &t){
        if(sum==0) return true;
        if(i>=arr.size() && sum!=0) return false;
        if(t[sum][i]!=-1) return (t[sum][i]==1)? true:false;
        
        if(arr[i]<=sum){
            bool take=helper(arr,sum-arr[i],i+1,t);
            t[sum][i]=(take==true)? 1:0;
            bool not_take=t[sum][i]=helper(arr,sum,i+1,t);
            t[sum][i]=(not_take==true)? 1:0;
            return take || not_take;
        }
        bool not_take=t[sum][i]=helper(arr,sum,i+1,t);
        t[sum][i]=(not_take==true)? 1:0;
        
        return not_take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>>t(sum+1,vector<int>(arr.size(),-1));
        return helper(arr,sum,0,t);
    }
};
```

*Generated on: 11/2/2026, 9:23:55 AM*