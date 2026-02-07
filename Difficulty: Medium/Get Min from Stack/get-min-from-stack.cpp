class SpecialStack {
  public:
    int top;
    stack<int> st;      // main stack
    stack<int> minSt;   // minimum stack
    SpecialStack() {
        // Define Stack
        top=-1;
    }

    void push(int x) {
        st.push(x);
        if (minSt.empty() || x <= minSt.top()) {
            minSt.push(x);
        }
    }

    // Pop element from stack
    void pop() {
        if (st.empty()) return;

        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    // Return top element
    int peek() {
        if (st.empty()) return -1;
        return st.top();
    }

    // Return minimum element
    int getMin() {
        if (minSt.empty()) return -1;
        return minSt.top();
    }

    // Check if stack is empty
    bool isEmpty() {
        return st.empty();
    }
};