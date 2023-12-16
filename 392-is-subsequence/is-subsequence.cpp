class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int n = s.size(), m = t.size();
        if(n == 0) return true;

        if(n == m) {
            return (s == t);
        }

        if(n > m) return false;

        while(j<m){
            while(j<m && t[j] != s[i]) j++;
            if(t[j] == s[i]){
                i++; j++;
            }
            if(i == n) return true;           
        }
        if(i == n) return true;
        return false;
    }
};