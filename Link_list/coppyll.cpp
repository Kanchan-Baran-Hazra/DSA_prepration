#include <bits/stdtr1c++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int x){
        this->data=x;
        this->next=NULL;
        this->random=NULL;
    }
};

class List{

    public:
    Node* head;
    Node* tail;
    unordered_map<int,Node*>mp;
    Node* last_node_data;

    List(){
        this->head=NULL;
        this->tail=NULL;
        this->last_node_data=NULL;
    }

    void push_back(int x){
        Node* newNode=new Node(x);
        mp[x]=newNode;
        newNode->random=last_node_data;
        last_node_data=newNode;

        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
        return;
    }

    void print(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<"-->"<<mp[temp->data]<<"-->"<<temp->random<<endl;
            temp=temp->next;
        }
    }

};

pair<Node*,unordered_map<int,Node*>> copy(Node* head,unordered_map<int,Node*>& mp){
    unordered_map<int,Node*>mp1;
    Node* temp=head;
    Node* prev=NULL;
    Node* new_head=NULL;

    while(temp!=NULL){
        Node* newNode=new Node(temp->data);
        mp1[newNode->data]=newNode;
        if(new_head==NULL) new_head=newNode;
        // newNode->random=mp1[mp[temp->data]->data];
        temp=temp->next;
        if(prev==NULL){
            prev=newNode;
            continue;
        }
        prev->next=newNode;
        prev=prev->next;
    }

    temp=head;
    while(temp!=NULL){
        Node* copidnode=mp1[temp->data];
        
        if(temp->random!=NULL){
            copidnode->random=mp1[temp->random->data];
        }
        temp=temp->next;
    }

    return {new_head,mp1};
}

void print(Node* head,unordered_map<int,Node*>& mp1){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"-->"<<mp1[temp->data]<<"-->"<<temp->random<<endl;
        temp=temp->next;
    }
}


int main(){

    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    ll.print();
    cout<<"\n";

    pair<Node*,unordered_map<int,Node*>> head=copy(ll.head,ll.mp);
    // for(auto x:head.second){
    //     cout<<x.first<<"-->"<<x.second<<"-->"<<endl;
    // }
    cout<<"\n";
    print(head.first,head.second);
    return 0;
}


