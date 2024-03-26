class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;
        for(int i = 0; i<g.size(); i++){
            while(j<s.size() && s[j] < g[i]){
                j++;
            }

            // s[j] >= g[i] or j == out of bounds
            if(j == s.size()) break;

            count++;
            j++;
        }
        return count;
    }
};