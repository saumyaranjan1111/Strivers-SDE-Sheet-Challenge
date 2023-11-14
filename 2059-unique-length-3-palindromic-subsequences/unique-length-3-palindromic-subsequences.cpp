class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        unordered_map<char, bool> vis;
        for(char c = 'a'; c<='z'; c++){
            vis[c] = false;
        }

        unordered_map<char, int> lastind;
        unordered_map<char, int> firstind;
        for(int i = 0; i<n; i++){
            if(firstind.find(s[i]) == firstind.end()){
                firstind[s[i]] = i;
            }
        }
        for(int i = n-1; i>=0; i--){
            if(lastind.find(s[i]) == lastind.end()){
                lastind[s[i]] = i;
            }
        }

        int count = 0;
        for(int i = 0; i<n; i++){
            if(vis[s[i]]) continue;
            int fi = firstind[s[i]];
            int li = lastind[s[i]];

            if(fi >= li) continue;
            int unique = unordered_set<char>(s.begin() + fi + 1, s.begin() + li).size();
            count+=unique;

            vis[s[i]] = true;
        }

        return count;
    }
};