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
    TreeNode* prev = NULL;
    TreeNode* temp1 = NULL;
    TreeNode* temp2 = NULL;

    void isallright(TreeNode* root){
        if(root==NULL) return;

        isallright(root->left);
        if(prev && prev->val>root->val){
            if(!temp1){
                temp1=prev;
            }
            temp2=root;
        }
        prev=root;

        isallright(root->right);
    }

    void recoverTree(TreeNode* root) {
        isallright(root);
        swap(temp1->val,temp2->val);
    }
};