using ll = long long;
class Solution {
private: 
    void _printMap(map<char, ll> &mp){
        for(auto it = mp.begin(); it!= mp.end(); it++){
            cout<<it->first<<" "<<it->second<<endl;
        }
    }
public:
    bool check(ll len, string &s, ll k){
        ll n = s.size();
        ll l = 0, r = len;

        if(len > n) return false;
        
        unordered_map<char, ll> freq;
        for(ll i = 0; i<r; i++){
            freq[s[i]]++;
        }
        
        // _printMap(freq);

        bool flag = true;
        for(auto it = freq.begin(); it!= freq.end(); it++){
            if(it->second < k){
                flag = false;
                break;
            }
        }

        if(flag) return true;

        while(r<n){
            freq[s[r]]++;
            freq[s[r - len]]--;

            if(freq[s[r - len]] == 0) freq.erase(freq.find(s[r - len]));

            bool temp = true;
            for(auto it = freq.begin(); it!= freq.end(); it++){
                if(it->second < k){
                    temp = false;
                    break;
                }
            }
            if(temp) return true;

            r++;
        }

        return false;
    }
    int longestSubstring(string s, int k) {
        ll n = s.size();
        ll maxlen = 0;
        for(ll len = 1; len <= n; len++){
            if(check(len, s, k)){
                maxlen = max(maxlen, len);
            }
        }

        return maxlen;
    }
};