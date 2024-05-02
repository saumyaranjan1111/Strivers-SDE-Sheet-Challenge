using ll = long long;
class Solution {
public:
    ll K;
    ll dp[12][2][12][12][20];
    ll f(ll ind, ll limit, ll even, ll digits, ll rem, string &hL, ll n){
        if(ind == n){
            if(digits > 0 && even*2 == digits && rem == 0) return 1;
            else return 0;
        }

        // dp[ind][limit][even][digits][rem] : no of beautiful nos such that
        // ind == current index that we are filling
        // limit == indicates whether the prefix is equal to the highestlimit
        // even == no of even digits in the no constructed till now
        // digits == total digits filled
        // rem == prefixtillnow % k

        if(dp[ind][limit][even][digits][rem] != -1) return dp[ind][limit][even][digits][rem];

        ll val = (limit == 0 ? 9 : hL[ind] - '0');
        // if limit is set (the prefix is equal to the highest possible till now)
        // then val should be equal to the hL[i], else we can choose from all digits 0->9

        ll currans = 0;
        for(ll digit = 0; digit <= val; digit++){
            if(digits == 0 && digit == 0){

                currans += f(ind+1, 0, 0, 0, 0, hL, n);
            } else {
                ll newind = ind+1;
                ll newlim = (limit == 1 && digit == hL[ind]-'0') ? 1 : 0;
                ll neweven = (digit % 2 == 0) ? even+1 : even;
                ll newdig = digits+1;
                ll newrem = (rem*10 + digit) % K;

                currans += f(newind, newlim, neweven, newdig, newrem, hL, n);
            } 
        }

        return dp[ind][limit][even][digits][rem] = currans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        K = k;
        string hL1 = to_string(high);
        memset(dp, -1, sizeof(dp));
        ll ans1 = f(0, 1, 0, 0, 0, hL1, hL1.size());

        string hL2 = to_string(low-1);
        memset(dp, -1, sizeof(dp));
        ll ans2 = f(0, 1, 0, 0, 0, hL2, hL2.size());

        // cout<<ans1<<endl;
        // cout<<ans2<<endl;
        return ans1-ans2;
    }
};