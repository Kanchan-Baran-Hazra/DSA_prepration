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
    static pair<bool,int> helper(TreeNode* root){
        if(root==NULL) return {true,0};

        pair<bool,int> temp1=helper(root->left);
        pair<bool,int> temp2=helper(root->right);

        if(temp1.first==false || temp2.first==false) return {false,0};
        if(abs(temp1.second-temp2.second)>1) return {false,0};

        return {true,max(temp1.second,temp2.second)+1};
    }
    bool isBalanced(TreeNode* root) {
        pair<bool,int> temp= helper(root);
        return temp.first;
    }
};