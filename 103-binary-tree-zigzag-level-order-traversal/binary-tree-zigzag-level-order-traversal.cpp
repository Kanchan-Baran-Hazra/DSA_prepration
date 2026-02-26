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
    void helper(TreeNode* root,vector<vector<int>>& ans){
        queue<pair<int,TreeNode*>>q;
        map<int,vector<int>>mp;

        q.push({0,root});

        while(q.size()>0){
            pair<int,TreeNode*> temp=q.front();
            q.pop();

            if(temp.second->left!=NULL){
                q.push({temp.first+1,temp.second->left});
            }
            if(temp.second->right!=NULL){
                q.push({temp.first+1,temp.second->right});
            }

            if(mp.find(temp.first)==mp.end()){
                vector<int>vec(1,temp.second->val);
                mp[temp.first]=vec;
            }else{
                vector<int>vec=mp[temp.first];
                vec.push_back(temp.second->val);
                mp[temp.first]=vec;
            }
        }

        for(auto x:mp){
            if(x.first%2==0) ans.push_back(x.second);
            else{
                reverse(x.second.begin(),x.second.end());
                ans.push_back(x.second);
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        helper(root,ans);

        return ans;
    }
};