class Solution {
  public:
    int floorDiv(int a, int b) {
        int q = a / b;
        int r = a % b;
        if (r != 0 && ((a < 0) ^ (b < 0)))
            q--;
        return q;
    }

    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {

            // operand (handles negative numbers)
            if (arr[i].size() > 1 || isdigit(arr[i][0])) {
                st.push(stoi(arr[i]));
            }
            else {
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();

                if (arr[i][0] == '+') st.push(second + first);
                else if (arr[i][0] == '-') st.push(second - first);
                else if (arr[i][0] == '*') st.push(second * first);
                else if (arr[i][0] == '/')
                    st.push(floorDiv(second, first));
                else
                    st.push((int)pow(second, first));
            }
        }
        return st.top();
    }
};


