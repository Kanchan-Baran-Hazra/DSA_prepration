// User function Template for C++

class Solution {
  public:
    int countNodes(Node* root) {
        // Write your code here
        if(root==NULL) return 0;
        
        int l=countNodes(root->left);
        int r=countNodes(root->right);
        
        return l+r+1;
    }
};