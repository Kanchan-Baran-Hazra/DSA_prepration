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


Node* insert(Node* root,Node* node){
    if(root==NULL) return node;
    else if(node->data>root->data) root->right=insert(root->right,node);
    else root->left=insert(root->left,node);
}

Node* root=NULL;
void buildTree(vector<int> nums){
    for(auto x:nums){
        Node* node=new Node(x);
        if(root==NULL){
            root=node;
            continue;
        }
        insert(root,node);
    }
}

void Preorder(Node* root){
    if(root==NULL) return;
    Preorder(root->left);
    cout<<root->data<<" ";
    Preorder(root->right);
}

int main(){
    vector<int> preorder={4,5,2,7,1,9,3,6,8};
    cout<<"Hello all right"<<endl;
    buildTree(preorder);
    Preorder(root);
    cout<<endl<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    return 0;
}