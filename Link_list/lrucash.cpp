#include<bits/stdc++.h>
using namespace std;

class LRUcashe{
    public:
    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key,int val){
            this->key=key;
            this->val=val;
            this->next=NULL;
            this->prev=NULL;
        }
    };

    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    int msize=1;
    unordered_map<int,Node*> mp;

    void delnode(Node* node){
        Node* prev1=node->prev;
        Node* temp=node->next;
        prev1->next=temp;
        temp->prev=prev1;
        node->prev=NULL;
        node->next=NULL;
        delete(node);
    }

    void addnode(Node* newnode){
        Node* temp=head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
    }

    LRUcashe(int x){
        this->msize=x;
        head->next=tail;
        tail->prev=head;
    }

    int get(int x){
        cout<<(mp.find(x)==mp.end())<<"\n\n";
        if(mp.find(x)==mp.end()) return -1;
        int data=mp[x]->val;

        delnode(mp[x]);
        Node* newnode=new Node(x,data);
        mp[x]=newnode;
        addnode(newnode);

        return data;
    }

    void put(int key,int val){
        if(mp.find(key)!=mp.end()){
            delnode(mp[key]);
            mp.erase(key);
        }
        else if(mp.size()==msize){
            mp.erase(key);
            delnode(tail->prev);
        }

        Node* newnode=new Node(key,val);
        mp[key]=newnode;
        addnode(newnode);
    }
};

int main(){
    // cout<<"hello"<<"\n";
    LRUcashe lc(2);

    lc.put(1,1);
    lc.put(2,2);
    cout<<lc.head->next<<"\n"<<lc.tail->prev<<"\n\n";
    cout<<lc.get(1)<<"\n";
    cout<<lc.head->next<<"\n"<<lc.tail->prev<<"\n\n";
    lc.put(3,3);
    cout<<lc.get(2)<<"\n";
    // cout<<lc.head->next<<"\n"<<lc.tail->prev<<"\n\n";
    // lc.put(4,4);
    // cout<<lc.get(1)<<"\n";
    // cout<<lc.get(3)<<"\n";
    // cout<<lc.get(4)<<"\n";
    return 0;
}