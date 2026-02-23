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
    vector<int> helper(Node* root){
        vector<int> ans;
        if(root == NULL){
            ans.push_back(0); // height
            ans.push_back(0); // diameter (edges)
            return ans;
        }
        
        vector<int> ans1 = helper(root->left);
        vector<int> ans2 = helper(root->right);
        
        // height
        ans.push_back(max(ans1[0], ans2[0]) + 1);
        
        // diameter in edges (NOT nodes)
        ans.push_back(max(max(ans1[1], ans2[1]), ans1[0] + ans2[0]));
        
        return ans;
    }

    int diameter(Node* root) {
        vector<int> ans = helper(root);
        return ans[1]; // diameter in edges
    }
};