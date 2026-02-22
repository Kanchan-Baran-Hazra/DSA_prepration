#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int x){
            data=x;
            left=NULL;
            right=NULL;
        }
};

static int idx=-1;
Node* buildTree(vector<int> nums){
    idx++;
    if(nums[idx]==-1) return NULL;

    Node* root=new Node(nums[idx]);
    root->left=buildTree(nums);
    root->right=buildTree(nums);

    return root;
}

void inorder(Node* root){
    if(root==NULL) return;
    
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

int main(){
    vector<int> Preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    cout<<"Hello all right"<<endl;
    Node* root=buildTree(Preorder);
    inorder(root);
    return 0;
}