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
    TreeNode* findIP(TreeNode* root){
        TreeNode* IP=root->left;
        while(IP->right!=NULL && IP->right!=root){
            IP=IP->right;
        }

        return IP;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* temp=root;
        while(temp!=NULL){
            if(temp->left==NULL){
                ans.push_back(temp->val);
                temp=temp->right;
            }else{
                TreeNode* IP=findIP(temp);
                if(IP->right==NULL){
                    IP->right=temp;
                    temp=temp->left;
                }else{
                    IP->right=NULL;
                    ans.push_back(temp->val);
                    temp=temp->right;
                }
            }
        }

        return ans;
    }
};