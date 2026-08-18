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
    void helper(TreeNode* root, string temp, vector<string>& ans) {
        if (!root) return;

        // Convert root->val properly to a string
        temp += to_string(root->val);

        // If it's a leaf, add path to answers
        if (!root->left && !root->right) {
            ans.push_back(temp);
            return;
        }

        // Add arrow for children
        temp += "->";

        helper(root->left, temp, ans);
        helper(root->right, temp, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root, "", ans);
        return ans;
    }
};