using ll = long long;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        ll n = s.size();

        vector<string> ans;
        if(n < 10) return ans;
        
        unordered_map<string, ll> mp;

        ll l = 0, r = 10;
        string curr = "";
        for(int i = 0; i<r; i++){
            curr+= s[i];
        }

        mp[curr]++;
        
        while(r < n){
            curr.erase(0, 1);
            curr += s[r];
            mp[curr]++;
            r++;
        }

        for(auto it = mp.begin(); it!= mp.end(); it++){
            if(it->second > 1){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};