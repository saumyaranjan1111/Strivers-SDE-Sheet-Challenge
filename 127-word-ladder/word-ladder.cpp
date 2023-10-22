class Solution {
private: 
    int hamming(string &s, string &t){
        int count = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] != t[i]) count++;
        }
        return count;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 0});

        int ans = INT_MAX;

        unordered_map<string, bool> vis;
        for(auto s: wordList){
            vis[s] = false;
        }

        while(!q.empty()){
            auto node = q.front();
            string str = node.first;
            int dist = node.second;

            q.pop();

            for(auto it = vis.begin(); it!= vis.end(); it++){
                if(it->second) continue;

                string t = it->first;
                int hamm = hamming(str, t);

                if(hamm == 1){
                    q.push({t, dist+1});
                    if(t == endWord){
                        return dist+2;
                    }
                    it->second = true;
                }
            }
        }

        return 0;
    }
};