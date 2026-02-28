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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        unsigned long long max_width=0;

        while(q.size()>0){
            int level_size=q.size();
            unsigned long long start=q.front().second;
            unsigned long long end=q.back().second;
            max_width=max(max_width,(end-start+1));

            for(int i=0;i<level_size;i++){
                pair<TreeNode*,unsigned long long> temp=q.front();
                q.pop();

                if(temp.first->left!=NULL){
                    q.push({temp.first->left,temp.second*2+1});
                }
                if(temp.first->right!=NULL){
                    q.push({temp.first->right,(temp.second*2)+2});
                }
            }
        }

        return max_width;
    }
};