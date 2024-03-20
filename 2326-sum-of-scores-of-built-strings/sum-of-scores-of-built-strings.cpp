using ll = long long;
class Solution {
public:
    auto z_algo(string str){
        ll len = str.size();
        ll l = 0, r = 0;
        vector<ll> z(len);
        for(ll i=1;i<len;i++){
            if(i>r){
                l=r=i;
                while(r<len && str[r]==str[r-l]) r++;
                z[i] = r-l;
                r--;
            } else {
                ll idx = i-l;
                if(i + z[idx] <= r){
                    z[i] = z[idx];
                } else {
                    l = i;
                    while(r<len && str[r]==str[r-l]) r++;
                    z[i] = r-l;
                    r--;
                }
            }
        }
        return z;
    }
    long long sumScores(string s) {
        auto z = z_algo(s);
        z[0] = s.size();
        ll ans = 0;
        for(auto x : z) ans+=x;

        return ans;
    }
};