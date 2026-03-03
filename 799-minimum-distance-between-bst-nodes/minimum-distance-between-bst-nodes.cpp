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
    void helper(TreeNode* root,vector<int>& temp){
        if(root==NULL) return;
        helper(root->left,temp);
        temp.push_back(root->val);
        helper(root->right,temp);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>temp;
        helper(root,temp);
        int mini=INT_MAX;

        for(int i=0;i<temp.size()-1;i++){
            mini=min(mini,temp[i+1]-temp[i]);
        }

        return mini;
    }
};