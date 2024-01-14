#define ll long long 
#define INF (ll)1e18
#define mod (ll)1e18
class Solution {
public:
    ll binpow(ll x, ll y){
        if(y == 0) return 1;

        ll rem = binpow(x, y/2);
        
        if(y%2 == 0) return rem*rem;
        return rem*rem*x;
    }
    ll check(ll num, int x){
        ll n = 0;
        // n is the position of the highest set bit
        // for 10 : n = 2, for 110 : n = 3
        ll temp = num;
        while(temp){
            temp >>= 1;
            n++;
        }

        ll count = 0;
        for(ll i = x; i<=n; i+=x){
            ll group_len = binpow(2, i);
            ll noofonesingroup = group_len/2;
            ll noofgroups = (num+1)/group_len;

            ll totalonesfromgroups = noofgroups*noofonesingroup;
            // remaining ones will be = remaining digits((num+1)%group_len)) - no of zeros(group_len/2)

            ll remones = max(0LL, (num+1)%group_len - (group_len/2));

            ll totalones = totalonesfromgroups + remones;
            // so total no of ones at this position i, == totalones

            count = (count%mod + totalones%mod)%INF;
        }
        return count;
    }
    long long findMaximumNumber(long long k, int x) {
        ll low = 1, high = INF;
        ll ans = low;
        while(low<=high){
            ll mid = low + (high - low)/2;
            // cout<<mid<<" ";
            // cout<<check(mid, x)<<endl;
            if(check(mid, x) <= k){
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }
};