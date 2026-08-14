#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Get maximum subsequence of length k
    static vector<int> getNums(vector<int>& nums, int k) {

        vector<int> ans;

        int remove = nums.size() - k;

        for (int x : nums) {

            while (!ans.empty() &&
                   remove > 0 &&
                   ans.back() < x) {

                ans.pop_back();
                remove--;
            }

            ans.push_back(x);
        }

        // If we still have elements to remove,
        // remove them from the end.
        ans.resize(k);

        return ans;
    }

    // Compare remaining portions of two vectors
    static bool greaterVec(vector<int>& a, int i,
                           vector<int>& b, int j) {

        while (i < a.size() && j < b.size()) {

            if (a[i] != b[j])
                return a[i] > b[j];

            i++;
            j++;
        }

        // If one is exhausted, the longer remaining
        // vector is considered greater.
        return (a.size() - i) > (b.size() - j);
    }

    // Merge two subsequences to create maximum number
    static vector<int> merge(vector<int>& a, vector<int>& b) {

        vector<int> ans;

        int i = 0;
        int j = 0;

        while (i < a.size() || j < b.size()) {

            if (greaterVec(a, i, b, j)) {
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }

        return ans;
    }

    // Compare two complete answers
    static bool greaterAnswer(vector<int>& a, vector<int>& b) {

        if (b.empty())
            return true;

        for (int i = 0; i < a.size(); i++) {

            if (a[i] != b[i])
                return a[i] > b[i];
        }

        return false;
    }

    vector<int> maxNumber(vector<int>& nums1,
                          vector<int>& nums2,
                          int k) {

        vector<int> ans;

        int n1 = nums1.size();
        int n2 = nums2.size();

        int start = max(0, k - n2);
        int end = min(k, n1);

        for (int i = start; i <= end; i++) {

            int j = k - i;

            vector<int> temp1 = getNums(nums1, i);
            vector<int> temp2 = getNums(nums2, j);

            vector<int> current = merge(temp1, temp2);

            if (greaterAnswer(current, ans)) {
                ans = current;
            }
        }

        return ans;
    }
};