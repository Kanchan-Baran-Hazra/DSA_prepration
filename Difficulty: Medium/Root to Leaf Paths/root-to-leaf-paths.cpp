/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void helper(Node* root,vector<vector<int>>& ans,vector<int>temp){
        temp.push_back(root->data);
        if(root->left==NULL && root->right==NULL){
            if(find(ans.begin(),ans.end(),temp)==ans.end() && temp.size()>0)
                ans.push_back(temp);
            return;
        }
        // temp.push_back(root->data);
        if(root->left!=NULL)
        helper(root->left,ans,temp);
        if(root->right!=NULL)
        helper(root->right,ans,temp);
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>temp;
        helper(root,ans,temp);
        
        return ans;
    }
};