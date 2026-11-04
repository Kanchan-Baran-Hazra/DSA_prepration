## 01. Longest Common Substring

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-common-substring1452/1)

### Problem Description

**Task:** Given two strings s1 and s2, determine the length of the longest substring that appears in both strings.Examples:Input: s1 = "ABCDGH", s2 = "ACDGHR"

#### Examples

##### Example 1

- **Output:**
```text
4
```
- **Explanation:** The longest common substring is "CDGH" with a length of 4.

##### Example 2

- **Input:**
```text
s1 = "abc", s2 = "acb"
```
- **Output:**
```text
1
```
- **Explanation:** The longest common substrings are "a", "b", "c" all having length 1.

##### Example 3

- **Input:**
```text
s1 = "YZ", s2 = "yz"
```
- **Output:**
```text
0Explanation: Comparison is case-sensitive, so 'Y' ≠ 'y' and 'Z' ≠ 'z'. Hence, no common substring exists.
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n * m)
- **Expected Auxiliary Space Complexity:** O(n * m)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-04 09:32:07
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    int longCommSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();

        // dp[i][j] stores the length of the longest common suffix 
        // ending at s1[i-1] and s2[j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxLength = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                } else {
                    dp[i][j] = 0; // Reset if characters don't match (contiguous requirement)
                }
            }
        }

        return maxLength;
    }
};
```

*Generated on: 11/4/2026, 9:32:56 AM*