class Solution {
public:
    void buildlps(vector<int> &lps, string pattern){
        int n = pattern.size();
        int i = 1;
        lps[0] = 0;
        int prevlps = 0;
        while(i<n){
            if(pattern[i] == pattern[prevlps]){
                lps[i] = prevlps + 1;
                prevlps++;
                i++;
            }
            else {
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
    int findneedle(string &haystack, string &needle, vector<int> &lps){
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
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();

        int areptimes = (int)ceil(m/(double)n) - 1;
        if(m < n) areptimes = 0;

        string temp = a;
        for(int i = 0; i<areptimes; i++){
            a += temp;
        }

        vector<int> lps(m, 0);
        buildlps(lps, b);

        int ind = findneedle(a, b, lps);
        if(ind != -1) return a.size()/temp.size();

        string a2 = a + temp;
        int ind2 = findneedle(a2, b, lps);
        if(ind2 != -1) return a.size()/temp.size() + 1;

        return -1;
        
    }
};