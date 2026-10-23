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
    Node* head;
    Node* tail;

    public:
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

    void pop_front(){
        if(head==NULL){
            cout<<"Empty LL..!!";
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }

    void pop_back(){
        if(head==NULL){
            cout<<"Empty LL..!!";
            return;
        }
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        Node* temp1=tail;
        tail=temp;
        temp->next=NULL;
        delete temp1;
    }

    void print(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

int main(){
    // cout<<"Hello";
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);

    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);

    ll.print();

    ll.pop_front();
    ll.pop_back();
    cout<<endl;
    ll.print();
    return 0;
}