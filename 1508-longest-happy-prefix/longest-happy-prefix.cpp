class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lps(s.size());
        int n = s.size();

        // create the lps array and take lps[n-1] characters from the start , that is the answer to this question

        lps[0] = 0;
        int prevlps = 0;
        int i = 1;

        while(i<n)
        {
            if(s[i] == s[prevlps])
            {
                lps[i] = prevlps+1;
                prevlps++;
                i++;
            }
            else
            {
                if(prevlps == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else
                {
                    prevlps = lps[prevlps-1];
                }
            }
        }
        string ans = "";
        int len = lps[n-1];
        for(int i = 0; i<len; i++)
        {
            ans+=s[i];
        }
        return ans;
    }
};