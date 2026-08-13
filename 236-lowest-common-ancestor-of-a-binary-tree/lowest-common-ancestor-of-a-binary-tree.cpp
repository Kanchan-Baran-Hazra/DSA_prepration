/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val==p->val || root->val==q->val) return root;

        TreeNode* le=lowestCommonAncestor(root->left,p,q);
        TreeNode* ri=lowestCommonAncestor(root->right,p,q);

        // if(le==NULL && ri==NULL) return NULL;
        if(le!=NULL && ri!=NULL) return root;

        return (le!=NULL)?le:ri;
    }
};