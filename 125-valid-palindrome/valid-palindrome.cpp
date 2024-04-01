class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(auto c : s){
            if(c == ' ') continue;
            c = tolower(c);
            if((c - 'a' <= 25 && c - 'a' >= 0) || (c - '0' <= 9 && c - '0' >= 0)) temp += c;
        }
        // cout<<temp<<endl;
        for(int i = 0, j = temp.size()-1; i<j; i++, j--){
            if(temp[i] != temp[j]) return false;
        }
        return true;
    }
};