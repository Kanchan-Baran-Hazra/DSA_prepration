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
    TreeNode* helper(vector<int>& preorder,int& temp,int upper){
        if(temp>=preorder.size() || preorder[temp]>upper) return NULL;
        TreeNode* node=new TreeNode(preorder[temp]);
        temp++;
        node->left=helper(preorder,temp,node->val);
        node->right=helper(preorder,temp,upper);

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int temp=0;
        return helper(preorder,temp,INT_MAX);
    }
};