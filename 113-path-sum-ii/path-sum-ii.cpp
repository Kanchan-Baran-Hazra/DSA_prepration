/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, int targetSum, vector<int>& temp, vector<vector<int>>& ans) {
        if (!root) return;

        temp.push_back(root->val);
        targetSum -= root->val; // Subtracting values avoids managing a separate sum variable

        // Check if it's a leaf node and the target sum is satisfied
        if (!root->left && !root->right && targetSum == 0) {
            ans.push_back(temp);
        } else {
            helper(root->left, targetSum, temp, ans);
            helper(root->right, targetSum, temp, ans);
        }

        temp.pop_back(); // Backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(root, targetSum, temp, ans);
        return ans;
    }
};