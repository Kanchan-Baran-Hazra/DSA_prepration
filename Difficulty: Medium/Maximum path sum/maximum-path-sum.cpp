/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int helper(Node* root,int& ans){
        if(root==NULL) return 0;
        
        int l=max(0,helper(root->left,ans));
        int r=max(0,helper(root->right,ans));
        ans=max(ans,root->data+l+r);
        
        return max(l,r)+root->data;
    }
    
    int findMaxSum(Node *root) {
        // code here
        int ans=INT_MIN;
        int num=helper(root,ans);
        return ans;
    }
};