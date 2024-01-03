using ll = long long;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, ll> mp, lookup;
        for(char c = 'a'; c<='z'; c++){
            lookup[c] = 0;
        }
        for(auto c : p){
            lookup[c]++;
        }
        int m = p.size(), n = s.size();
        for(int i = 0; i<m; i++){
            mp[s[i]]++;
        }

        vector<int> ans;
        bool flag = true;
        for(auto it = mp.begin(); it!= mp.end(); it++){
            if(it->second > 0 && lookup[it->first] != it->second){
                flag = false;
                break;
            }
        }
        if(flag){
            ans.push_back(0);
        }

        ll r = m;
        while(r < n){
            mp[s[r]]++;
            mp[s[r - m]]--;

            bool temp = true;
            for(auto it = mp.begin(); it!= mp.end(); it++){
                if(it->second > 0 && lookup[it->first] != it->second){
                    temp = false;
                    break;
                }
            }
            if(temp) ans.push_back(r-m+1);
            r++;
        }

        return ans;
    }
};