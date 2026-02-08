class Solution {
  public:
    void helper(stack<int>& s,int pos){
        if(s.size()==pos){
            s.pop();
            return;
        }
        int temp=s.top();
        s.pop();
        helper(s,pos);
        s.push(temp);
    }
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int n=s.size();
        int pos;
        if(n%2!=0) pos=(n/2)+1;
        else pos=n/2;
        helper(s,pos);
    }
};