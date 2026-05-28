class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int x) {
        val = x;
        next = NULL;
        prev = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    MyLinkedList() { head = NULL; }

    int get(int index) {
        Node* ptr = head;
        int i = 0;
        while (ptr != NULL) {
            if (index == i)
                return ptr->val;
            ptr = ptr->next;
            i++;
        }
        return -1;
    }

    void addAtHead(int val) {
        Node* current = new Node(val);
        if (head != NULL)
            head->prev = current;
        current->next = head;
        head = current;
    }

    void addAtTail(int val) {
        Node* new_node = new Node(val);
        Node* temp = head;
        if (head == NULL) {
            head = new_node;
            return;
        }
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->prev = temp;
        return;
    }

    void addAtIndex(int index, int val) {

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;

        int i = 0;

        while (temp != NULL && i < index - 1) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL)
            return;

        Node* newNode = new Node(val);

        Node* temp1 = temp->next;

        temp->next = newNode;

        newNode->prev = temp;

        newNode->next = temp1;

        if (temp1 != NULL)
            temp1->prev = newNode;
    }

    void deleteAtIndex(int index) {

        if (head == NULL)
            return;

        if (index == 0) {

            Node* temp = head;

            head = head->next;

            if (head != NULL)
                head->prev = NULL;

            delete temp;

            return;
        }

        Node* temp = head;

        int i = 0;

        while (temp != NULL && i < index - 1) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL || temp->next == NULL)
            return;

        Node* delNode = temp->next;

        temp->next = delNode->next;

        if (delNode->next != NULL)
            delNode->next->prev = temp;

        delete delNode;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */