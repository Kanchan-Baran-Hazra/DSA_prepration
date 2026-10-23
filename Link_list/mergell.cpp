#include <bits/stdtr1c++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int x){
        this->data=x;
        this->next=NULL;
    }
};

class List{

    public:
    Node* head;
    Node* tail;
    
    List(){
        this->head=NULL;
        this->tail=NULL;
    }

    void push_front(int x){
        Node* newNode=new Node(x);

        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
        return;
    }

    void push_back(int x){
        Node* newNode=new Node(x);

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
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

};

Node* merge2LL(Node* ll1,Node* ll2){
    if(ll1==NULL) return ll2;
    if(ll2==NULL) return ll1;

    if(ll1->data<ll2->data){
        ll1->next=merge2LL(ll1->next,ll2);
        return ll1;
    }else{
        ll2->next=merge2LL(ll1,ll2->next);
        return ll2;
    }
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    // cout<<"Hello";
    List ll;

    ll.push_back(1);
    // ll.push_back(2);
    ll.push_back(3);
    // ll.push_back(4);
    ll.push_back(5);

    List ll2;

    ll2.push_back(2);
    ll2.push_back(3);
    ll2.push_back(6);

    ll.print();
    cout<<"\n";
    ll2.print();
    cout<<"\n";
    Node* head=merge2LL(ll.head,ll2.head);
    print(head);

    return 0;
}