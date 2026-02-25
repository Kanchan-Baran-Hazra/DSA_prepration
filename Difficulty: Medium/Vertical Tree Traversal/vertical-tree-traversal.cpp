/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void helper(Node* root,vector<vector<int>> &ans){
        queue<pair<int,Node*>>q;
        map<int,vector<int>>mp;
        q.push({0,root});
        
        while(q.size()>0){
            pair<int,Node*> temp=q.front();
            q.pop();
            
            if(temp.second->left!=NULL){
                q.push({temp.first-1,temp.second->left});
            }
            if(temp.second->right!=NULL){
                q.push({temp.first+1,temp.second->right});
            }
            
            if(mp.find(temp.first)==mp.end()){
                vector<int>sub(1,temp.second->data);
                mp[temp.first]=sub;
            }else{
                vector<int>tempvec=mp[temp.first];
                tempvec.push_back(temp.second->data);
                mp[temp.first]=tempvec;
            }
        }
        
        for(auto x:mp){
            ans.push_back(x.second);
        }
    }
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>>ans;
        helper(root,ans);
        
        return ans;
    }
};