// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
class Solution {
public:
    Node* reverseBetween(int a, int b, Node* head) {
        Node* dumNode = new Node(0);
        dumNode->next = head;

        Node* lptr = dumNode;

        // move to (a-1)th node
        for(int i = 1; i < a; i++){
            lptr = lptr->next;
        }

        Node* temp = lptr->next;
        Node* ltemp = temp;
        Node* prenode = NULL;

        // reverse (b-a+1) nodes
        for(int i = 0; i <= b - a; i++){
            Node* nextNode = temp->next;
            temp->next = prenode;
            prenode = temp;
            temp = nextNode;
        }

        // reconnect
        lptr->next = prenode;
        ltemp->next = temp;

        return dumNode->next;
    }
};