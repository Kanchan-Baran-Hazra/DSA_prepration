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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        int x=0;
        int y=0;
        if(root->left!=NULL){
            x=minDepth(root->left);
        }
        if(root->right!=NULL){
            y=minDepth(root->right);
        }

        if(x!=0 && y!=0) return min(x,y)+1;
        else if(x!=0) return x+1;
        else if(y!=0) return y+1;
        return 1;
    }
};