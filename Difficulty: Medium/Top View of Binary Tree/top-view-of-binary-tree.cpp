/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void helper(Node* root,vector<int> &ans){
        queue<pair<int,Node*>>q;
        map<int,int>mp;
        
        q.push({0,root});
        
        while(q.size()>0){
            pair<int,Node*> temp = q.front();
            q.pop();
            
            if(temp.second->left!=NULL){
                q.push({temp.first-1,temp.second->left});
            }
            if(temp.second->right!=NULL){
                q.push({temp.first+1,temp.second->right});
            }
            
            if(mp.find(temp.first)==mp.end()){
                mp[temp.first]=temp.second->data;
            }
        }
        
        for(auto x:mp){
            ans.push_back(x.second);
        }
    }
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        helper(root,ans);
        
        return ans;
    }
};