/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    int helper(Node* root){
        if(root==NULL) return 0;
        
        int l=helper(root->left);
        int r=helper(root->right);
        
        if(l==0 && r==0) return 1;
        else if(l==0) return r+1;
        else if(r==0) return l+1;
        else return min(r,l)+1;
    }
    /*You are required to complete this method*/
    int minDepth(Node *root) {
        // Your code here
        if(root->left==NULL && root->right==NULL) return 0;
        int ans=0;
        return helper(root);
    }
};