#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int x){
        this->data=x;
        this->next=NULL;
        this->prev=NULL;
        this->child=NULL;
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

    Node* flatten(Node* head){
        Node* temp=head;
        while(temp!=NULL && temp->child==NULL) temp=temp->next;
        if(temp->child!=NULL){
            Node* temp_next=temp->next;
            temp->next=flatten(temp->child);
            temp->next->prev=temp;
            temp->child=NULL;
            while(temp->next!=NULL) temp=temp->next;
            if(temp!=NULL){
                temp->next=temp_next;
                temp_next->prev=temp;
            }
        }
    }

};



int main(){
    return 0;
}