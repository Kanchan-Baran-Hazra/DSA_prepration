/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    pair<int,int> helper(Node* root){
        if(root==NULL) return {0,0};
        
        int cur_val=root->data;
        pair<int,int> l=helper(root->left);
        pair<int,int> r=helper(root->right);
        root->data=l.first+l.second+r.first+r.second;
        return {cur_val,l.first+l.second+r.first+r.second};
    }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node) {
        // Your code here
        pair<int,int>temp=helper(node);
    }
};