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
    int search(int num,vector<int>& inorder,int i,int j){
        for(int k=i;k<=j;k++){
            if(inorder[k]==num) return k;
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int& idx,int i,int j){
        if(i>j) return NULL;

        TreeNode* node=new TreeNode(preorder[idx]);
        int index=search(preorder[idx],inorder,i,j);
        idx++;
        node->left=helper(preorder,inorder,idx,i,index-1);
        node->right=helper(preorder,inorder,idx,index+1,j);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        return helper(preorder,inorder,idx,0,inorder.size()-1);
    }
};