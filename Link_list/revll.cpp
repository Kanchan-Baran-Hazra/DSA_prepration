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

    void reverse_list(){
        if(head==NULL || head->next==NULL) return;
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
        return;
    }

    int middle_of_ll(){
        Node* slow=head;
        Node* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow->data;
    }

    bool detect_cycle(){
        Node* slow=head;
        Node* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }

    void remove_cycle(){
        if(this->detect_cycle()){
            Node* slow=head;
            Node* fast=head;

            while(1){
                slow=slow->next;
                fast=fast->next->next;
                if(slow==fast) break;
            }

            slow=head;
            Node* prev=NULL;
            while(slow!=fast){
                slow=slow->next;
                prev=fast;
                fast=fast->next;
            }

            prev->next=NULL;
            return;
        }

        return;
    }

    void create_circle(){
        Node* temp=head;
        int count=1;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }

        if(count<3) tail->next=head;
        else{
            tail->next=head->next->next;
        }

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


    // ll.reverse_list();
    // cout<<endl;
    // ll.print();
    cout<<endl;
    // cout<<ll.middle_of_ll();
    // cout<<endl;
    // ll.create_circle();
    // cout<<ll.detect_cycle();
    // ll.remove_cycle();
    // cout<<endl;
    // cout<<ll.detect_cycle()<<endl;
    ll.print();
    
    return 0;
}