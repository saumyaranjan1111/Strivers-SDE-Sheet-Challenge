class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto s: tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                
                swap(x, y);
                
                if(s == "+") st.push(x + y);
                if(s == "-") st.push(x - y);
                if(s == "*") st.push(x * y);
                if(s == "/") st.push(x / y);
            } else st.push(stoi(s));
        }
        return st.top();
    }
};