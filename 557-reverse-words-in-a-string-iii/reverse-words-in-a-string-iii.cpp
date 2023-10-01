class Solution {
public:
    string rev(string s){
        reverse(s.begin(), s.end());
        return s;
    }
    string reverseWords(string s) {
        vector<string> v;
        int n = s.size();

        string temp = "";
        for(int i = 0; i<n; i++){
            if(s[i] == ' '){
                v.push_back(temp);
                temp = "";
            }
            else{
                temp+=s[i];
            }

            if(i == n-1){ v.push_back(temp); }
        }
        string ans = "";
        for(auto word:v){
            ans+=rev(word) + " ";
        }
        ans.pop_back();
        return ans;
    }
};