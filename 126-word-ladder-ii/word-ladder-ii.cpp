class Solution {
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
private:
    void dfs(string &s, vector<string>& currpath, string &start, string &endd){
        if(s == start){
            ans.push_back(currpath);
            return;
        }

        int level = mp[s];
        for(int i = 0; i<s.size(); i++){
            char og = s[i];
            for(char ch = 'a'; ch<='z'; ch++){
                s[i] = ch;
                if(mp.find(s) != mp.end() && mp[s]+1 == level){
                    currpath.push_back(s);
                    dfs(s, currpath, start, endd);
                    currpath.pop_back();
                }
            }
            s[i] = og;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        string beg = beginWord;
        mp[beg] = 0;

        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beg);

        st.erase(beginWord);
        
        while(!q.empty()){
            string str = q.front();
            int prev = mp[str];
            q.pop();
            
            if(str == endWord) break;

            for(int i = 0; i<str.size(); i++){
                char og = str[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    str[i] = ch;
                    if(st.find(str) != st.end()){
                        q.push(str);
                        mp[str] = prev + 1;
                        st.erase(str);

                        if(str == endWord) break;
                    }
                }
                str[i] = og;
            }
        }
        vector<string> currpath;
        currpath.push_back(endWord);
        dfs(endWord, currpath, beginWord, endWord);

        for(int i = 0; i<ans.size(); i++){
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};