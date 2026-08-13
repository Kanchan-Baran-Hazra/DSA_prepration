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
    int maxi=INT_MIN;
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int x=helper(root->left);
        int y=helper(root->right);
        x = max(0, x);
        y = max(0, y);
        maxi=max(maxi,x+y+root->val);
        return max(x,y)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int temp=helper(root);
        return max(temp,maxi);
    }
};