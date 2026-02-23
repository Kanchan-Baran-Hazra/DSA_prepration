/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int helper(Node* root){
        if(root==NULL) return 0;
        
        int left=helper(root->left);
        int right=helper(root->right);
        
        return max(left,right)+1;
    }
    
    int height(Node* root) {
        // code here
        return helper(root)-1;
    }
};