class Solution {
public:
    void makelps(vector<int>& lps, string s){
        int n = s.size();
        lps[0] = 0;
        int prevlps = 0;
        int i = 1;
        while(i<n){
            if(s[i] == s[prevlps]){
                lps[i] = prevlps + 1;
                i++; prevlps++;
            }
            else{
                if(prevlps == 0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    prevlps = lps[prevlps - 1];
                }
            }
        }
    }
    bool repeatedSubstringPattern(string s) {
        vector<int> lps(s.size(), 0);
        makelps(lps, s);
        int n = s.size();

        if(lps[n-1] != 0 && (n % (n - lps[n-1]) == 0)) return true;
        return false;
    }
};