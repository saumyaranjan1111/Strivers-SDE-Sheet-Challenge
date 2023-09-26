class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> mp;
        for(int i = 0; i<s.size(); i++){
            mp[s[i]]++;
        }
        map<char, int> currmp;
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            
                if(currmp.find(s[i]) == currmp.end() || currmp[s[i]] == 0){

                    while(!st.empty() && st.top() > s[i] && mp[st.top()]>0){
                        currmp[st.top()]--;
                        st.pop();
                    }
                }
                else {
                    mp[s[i]]--;
                }
                if(currmp.find(s[i]) == currmp.end() || currmp[s[i]] == 0)
                    {st.push(s[i]);
                    mp[s[i]]--;
                    currmp[s[i]]++;}
            
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};