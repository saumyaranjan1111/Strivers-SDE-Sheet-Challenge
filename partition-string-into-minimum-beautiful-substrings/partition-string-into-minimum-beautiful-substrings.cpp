#define ll long long
class Solution {
public:
    ll minimumBeautifulSubstrings(string s) {
        ll n = s.size();

        vector<ll> dp(n+1, INT_MAX);
        // dp[i] : minimum no of beautiful strings in the string from 0 to i-1
        dp[0] = 0;
        // no beautiful strings before 0th index

        for(ll i = 0; i<n; i++){
            // we skip all the s[i] == '0' because there cant be a beautiful substring from i to j, if it starts with 0.
            if(s[i] == '1')
            {
                ll curr = 0;
                for(ll j = i; j<n; j++){
                    curr  = (curr<<1) + (s[j] - '0');
                    // adding the next character into the current string
                    // if the current suffix from i+1 to j is a pow of 5, then the no of strings would be the minimum no of strings before this current string -> s[i], + 1 (accounting for the suffix), so dp[j+1] = min(dp[j+1], dp[i] + 1)
                    if(15625 % curr == 0)
                    {
                        dp[j+1] = min(dp[j+1], dp[i] + 1);
                    }
                }
            }
        }

        if(dp[n] > n) return -1;
        else return dp[n];
    }
};