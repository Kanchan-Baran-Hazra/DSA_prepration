class myQueue {

  public:
    stack<int>st1;
    stack<int>st2;
    myQueue() {
        // Initialize your data members
    }

    void enqueue(int x) {
        // Implement enqueue operation
        while(st1.size()!=0){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(st2.size()!=0){
            st1.push(st2.top());
            st2.pop();
        }
    }

    void dequeue() {
        // Implement dequeue operation
        st1.pop();
        
    }

    int front() {
        // Implement front operation
        if(st1.size()==0) return -1;
        return st1.top();
    }

    int size() {
        // Implement size operation
        return st1.size();
    }
};
