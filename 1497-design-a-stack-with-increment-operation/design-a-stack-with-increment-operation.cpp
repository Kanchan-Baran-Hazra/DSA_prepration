class CustomStack {
public:
    int x;
    stack<int>st;
    stack<int>st1;
    CustomStack(int maxSize) {
        x=maxSize;
    }
    
    void push(int z) {
        if(st.size()<x) st.push(z);
    }
    
    int pop() {
        if(st.size()==0) return -1;
        int y=st.top();
        st.pop();
        return y;
    }
    
    void increment(int k, int val) {
        while(st.size()!=0){
            st1.push(st.top());
            st.pop();
        }

        while(st1.size()!=0 && k>0){
            int y=st1.top();
            st1.pop();
            st.push(y+val);
            k--;
        }

        while(st1.size()!=0){
            st.push(st1.top());
            st1.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */