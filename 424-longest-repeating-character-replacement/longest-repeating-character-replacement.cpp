using ll = long long;
class Solution {
public:
    bool check(ll len, string &s, ll k){
        // is it possible to have a substring of length == len, such that all the characters are the same using <= k operations ? 
        
        ll n = s.size();
        unordered_map<char, ll> mp;
        for(ll i = 0; i<len; i++){
            mp[s[i]]++;
        }
        ll maxf = 0;
        for(auto it = mp.begin(); it!= mp.end(); it++){
            maxf = max(maxf, it->second);
        }
        ll rem = len - maxf;
        if(rem <= k) return true;

        ll r = len;
        while(r < n){
            mp[s[r - len]]--;
            mp[s[r]]++;

            ll maxf = 0;
            for(auto it = mp.begin(); it!= mp.end(); it++){
                maxf = max(maxf, it->second);
            }
            ll rem = len - maxf;
            if(rem <= k) return true;

            r++;
        }

        return false;
    }
    int characterReplacement(string s, int k) {
        ll n = s.size();
        ll low = 1, high = n;
        ll ans = low;
        while(low<=high){
            ll mid = low + (high - low)/2;

            if(check(mid, s, k)){
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }

        return (int)ans;
    }
};