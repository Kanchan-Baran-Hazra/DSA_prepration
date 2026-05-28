class SpecialStack {
  public:
    stack<int>st1;
    stack<int>mx;

    SpecialStack() {

    }

    void push(int x) {
        st1.push(x);

        if(mx.empty() || x >= mx.top()){
            mx.push(x);
        }
    }

    void pop() {
        if(st1.empty()) return;

        if(st1.top() == mx.top()){
            mx.pop();
        }

        st1.pop();
    }

    int peek() {
        if(st1.empty()) return -1;

        return st1.top();
    }

    bool isEmpty() {
        return st1.empty();
    }

    int getMax() {
        if(mx.empty()) return -1;

        return mx.top();
    }
};