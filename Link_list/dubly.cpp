#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int x){
        this->data=x;
        this->next=NULL;
        this->prev=NULL;
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
        if(tail==NULL) tail=newNode;
        newNode->next=head;
        head=newNode;
        if(head->next!=NULL)
        head->next->prev=head;
        return;
    }

    void print(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    void push_back(int x){
        Node* newNode=new Node(x);
        tail->next=newNode;
        newNode->prev=tail;
        tail=tail->next;
        return;
    }

    void pop_back(){
        if(head==NULL) return;

        Node* temp=tail->prev;

        temp->next=NULL;
        tail->prev=NULL;
        tail=temp;
        return;
    }

    void pop_front(){
        if(head==NULL) return;

        Node* temp=head->next;

        head->next=NULL;
        temp->prev=NULL;
        head=temp;
        return;
    }

    int node_count(){
        if(head==NULL) return 0;
        int count=0;
        Node* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }

        return count;
    }

};

int main(){

    List ll;


    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);

    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);

    ll.print();

    cout<<"\n"<<ll.node_count()<<"\n";

    ll.pop_front();
    ll.pop_front();

    ll.print();

    cout<<"\n"<<ll.node_count()<<"\n";

    ll.pop_back();
    ll.pop_back();

    ll.print();
    cout<<ll.node_count()<<"\n";

    return 0;
}