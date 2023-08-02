typedef long long   ll;
ll mod = 1000000007;


class Solution {
public:
    int dp[101][2][2][11];

    ll go(ll pos, ll tight, ll zeros, ll prev, string &s){
        if(pos == (ll)s.size()){
            if(zeros) return 0;
            return 1;
        }

        if(dp[pos][tight][zeros][prev + 1] != -1){
            return dp[pos][tight][zeros][prev + 1];
        }

        ll result = 0;
        ll limit;

        if(tight) limit = (s[pos] - '0');
        else limit = 9;

        for(ll i = 0; i<=limit; i++){
            ll newtight = tight;
            if(tight && (i < limit)) newtight = 0;

            ll newzeros = zeros;
            if(zeros && i > 0) newzeros = 0;

            if(zeros){
                result += go(pos + 1, newtight, newzeros, i, s);
                result %= mod;
            }
            else {
                if(abs(i - prev) == 1){
                    result += go(pos + 1, newtight, newzeros, i, s);
                    result %= mod;
                }
            }
        }

        return dp[pos][tight][zeros][prev + 1] = result;

    }
    int countSteppingNumbers(string low, string high) {
        
        memset(dp, -1, sizeof(dp));
        int ans1 = go(0, 1, 1, -1, low);

        memset(dp, -1, sizeof(dp));
        int ans2 = go(0, 1, 1, -1, high);

        ll result = ans2 - ans1;
        result%=mod;
        result+=mod;
        result%=mod;

        bool flag = true;
        for(int i = 1; i<low.size(); i++){
            if(abs(low[i] - low[i-1])!=1)
            {
                flag = false; break;
            }
        }

        if(flag) result++;
        result%=mod;

        return result;

    }
};