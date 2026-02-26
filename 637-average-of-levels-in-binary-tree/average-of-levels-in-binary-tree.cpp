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
    void helper(TreeNode* root,vector<double>& ans){
        queue<pair<int,TreeNode*>>q;
        map<int,pair<int,long>>mp;

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
                mp[temp.first]={1,temp.second->val};
            }else{
                pair<int,long> val=mp[temp.first];
                val.first++;
                val.second+=temp.second->val;
                mp[temp.first]=val;
            }
        }

        for(auto x: mp){
            ans.push_back((double)x.second.second/x.second.first);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        helper(root,ans);

        return ans;
    }
};