class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        stack<char> st;
        for(auto c : s){
            if(c != ']'){
                st.push(c);
            } else {
                string temp = "";
                while(!st.empty() && st.top() != '['){
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();

                string num = "";
                while(!st.empty() && st.top()-'0' <= 9){
                    // st.top() is a number
                    num = st.top() + num;
                    st.pop();
                }
                // reverse(num.begin(), num.end());

                int times = stoi(num);

                for(int i = 0; i<times; i++){
                    for(int j = 0; j<temp.size(); j++){
                        st.push(temp[j]);
                    }
                }
            }
        }
        while(!st.empty()) {
            ans += st.top(); st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};