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

    void rev_in_pair(){
        if(head==NULL || head->next==NULL) return;
        head=helper(head);
        return;
    }

    Node* helper(Node* head){
        if(head==NULL || head->next==NULL) return head;
        Node* temp1=head;
        Node* temp2=head->next;
        Node* temp3=temp2->next;

        temp2->next=temp1;
        temp1->next=helper(temp3);
        return temp2;
    }

    int getlen(){
        Node* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }

    Node* helperTailFinder(Node* temp,int k){
        while(temp!=NULL && k!=0){
            if(temp==NULL) return temp;
            temp=temp->next;
            k--;
        }
        return temp;
    }

    Node* helperKgroup(Node* head,int k){
        Node* temp=head;
        tail=helperTailFinder(head,k);
        if(tail!=NULL){
            Node* temp1=helperKgroup(tail->next,k);
            pair<Node*,Node*> x =revll(head,tail);

            x.second->next=temp1;
            return x.first;
        }else{
            return head;
        }
        return head;
    }

    void revKgroup(int k){
        head=helperKgroup(head,k);
        return;
    }

    pair<Node*,Node*> revll(Node* head,Node* tail){
        if(head==NULL || head->next==NULL) return {head,tail};
        Node* prev=NULL;
        Node* temp1=head;
        Node* temp2=head->next;
        tail=head;

        while(temp1!=NULL){
            temp1->next=prev;
            prev=temp1;
            temp1=temp2;
            if(temp2!=NULL)
            temp2=temp2->next;
        }

        head=prev;
        return {head,tail};
    }

    void reverse(){
        head=revll(head,tail);
        return;
    }
};


int main(){
    // cout<<"Hello";
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    ll.print();
    // ll.rev_in_pair();
    // cout<<"\n";
    // ll.print();

    // ll.reverse();
    ll.revKgroup(5);
    cout<<"\n";
    ll.print();
}