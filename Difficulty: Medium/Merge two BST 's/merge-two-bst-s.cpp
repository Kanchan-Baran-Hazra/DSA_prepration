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
    void helper(Node* root,vector<int>& vec){
        if(root==NULL) return;
        helper(root->left,vec);
        vec.push_back(root->data);
        helper(root->right,vec);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        vector<int>temp1;
        vector<int>temp2;
        helper(root1,temp1);
        helper(root2,temp2);
        
        temp1.insert(temp1.end(),temp2.begin(),temp2.end());
        sort(temp1.begin(),temp1.end());
        
        return temp1;
    }
};