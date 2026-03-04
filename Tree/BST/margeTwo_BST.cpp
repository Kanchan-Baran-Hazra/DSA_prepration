#include<iostream>
#include<vector>
#include <algorithm>
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

Node* root1=NULL;
void buildTree1(vector<int> nums){
    for(auto x:nums){
        Node* node=new Node(x);
        if(root1==NULL){
            root1=node;
            continue;
        }
        insert(root1,node);
    }
}

void Preorder(Node* root){
    if(root==NULL) return;
    Preorder(root->left);
    cout<<root->data<<" ";
    Preorder(root->right);
}

void getPreorder(Node* root,vector<int>& temp){
    if(root==NULL) return;
    getPreorder(root->left,temp);
    temp.push_back(root->data);
    getPreorder(root->right,temp);
}

Node* getBalanceTree(vector<int>& temp,int i,int j){
    if(i>j) return NULL;
    int mid=i+(j-i)/2;
    Node* node=new Node(temp[mid]);
    node->left=getBalanceTree(temp,i,mid-1);
    node->right=getBalanceTree(temp,mid+1,j);

    return node;
}

Node* margeTree(Node* root,Node* root1){
    vector<int>temp1;
    vector<int>temp2;
    getPreorder(root,temp1);
    getPreorder(root1,temp2);
    temp1.insert(temp1.end(),temp2.begin(),temp2.end());
    sort(temp1.begin(),temp1.end());
    return getBalanceTree(temp1,0,temp1.size()-1);
}

int main(){
    vector<int> preorder={4,5,2,7};
    vector<int> preorder1={1,9,3,6,8};
    cout<<"Hello all right"<<endl;
    buildTree(preorder);
    buildTree1(preorder1);
    // Preorder(root);
    // cout<<endl;
    // Preorder(root1);
    Node* finalRoot=margeTree(root,root1);
    Preorder(finalRoot);
    // cout<<endl<<root->left->data<<endl;
    // cout<<root->right->data<<endl;
    return 0;
}