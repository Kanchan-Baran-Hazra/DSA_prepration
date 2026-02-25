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
    bool isidentical(TreeNode* root,TreeNode* root1){
        if(root==NULL || root1==NULL) return root==root1;

        return isidentical(root->left,root1->left) && isidentical(root->right,root1->right) && root->val==root1->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        bool rootBool=false;

        if(root->val==subRoot->val) rootBool= isidentical(root,subRoot);
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot) || rootBool;
    }
};