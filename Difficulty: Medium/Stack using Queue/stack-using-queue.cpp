class myStack {
    queue<int> q;

  public:
    queue<int>q1;
    queue<int>q2;
    void push(int x) {
        // Inserts an element x at the top of the stack
        while(q1.size()!=0){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(q2.size()!=0){
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop() {
        // Removes an element from the top of the stack
        if(q1.size()!=0)
            q1.pop();
    }

    int top() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(q1.size()==0) return -1;
        return q1.front();
    }

    int size() {
        // Returns the current size of the stack
        return q1.size();
    }
};
