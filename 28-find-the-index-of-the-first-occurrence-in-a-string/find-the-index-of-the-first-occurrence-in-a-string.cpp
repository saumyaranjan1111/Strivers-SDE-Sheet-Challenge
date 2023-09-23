class Solution {
public:
    void buildlps(string pattern, vector<int> &lps){
        lps[0] = 0;
        int i = 1;
        int prevlps = 0;
        int n = pattern.size();
        while(i<n){
            if(pattern[i] == pattern[prevlps]){
                lps[i] = prevlps + 1;
                prevlps++;
                i++;
            }
            else{
                if(prevlps == 0){
                    lps[i] = 0;
                    i++;
                }
                else {
                    prevlps = lps[prevlps-1];
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        buildlps(needle, lps);

        int i = 0;
        int j = 0;

        while(i<haystack.size())
        {
            if(haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j==0)
                {
                    i++;
                }
                else
                {
                    j = lps[j-1];
                }
            }
            if(j==needle.size())
            {
                return i - needle.size();
            }
        }
        return -1;
    }
};