class myQueue {
public:
    int front, rear, n;
    vector<int> arr;

    myQueue(int n) {
        this->n = n;
        arr.resize(n);
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % n == front;
    }

    void enqueue(int x) {
        if (isFull()) return;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % n;
        }
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) return;

        if (front == rear) {
            front = rear = -1;   // queue becomes empty
        } else {
            front = (front + 1) % n;
        }
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};


