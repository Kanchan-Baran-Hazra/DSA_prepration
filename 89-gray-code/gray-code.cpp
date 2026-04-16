class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return {0};
        if (n == 1) return {0, 1};

        vector<int> temp = grayCode(n - 1);
        vector<int> ans = temp;

        int add = 1 << (n - 1);

        for (int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i] + add);
        }

        return ans;
    }
};