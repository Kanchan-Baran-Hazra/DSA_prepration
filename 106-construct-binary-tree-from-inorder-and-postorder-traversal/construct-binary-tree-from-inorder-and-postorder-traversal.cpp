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
    static int search(vector<int> &inorder,int x,int i,int j){
        for(int k=i;k<=j;k++){
            if(inorder[k]==x) return k;
        }
        return -1;
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int &idx,int i,int j){
        if(i>j) return NULL;
        int index=search(inorder,postorder[idx],i,j);
        TreeNode* root=new TreeNode(postorder[idx]);
        idx--;
        root->right=helper(inorder,postorder,idx,index+1,j);
        root->left=helper(inorder,postorder,idx,i,index-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx=postorder.size()-1;
        return helper(inorder,postorder,idx,0,inorder.size()-1);
    }
};