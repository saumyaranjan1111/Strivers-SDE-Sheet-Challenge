using ll = long long;
class Solution {
public:
    ll f(ll ind, ll mask, vector<int> &nums1, vector<int> &nums2, vector<vector<ll>>&dp){
        ll n = dp.size()-1;
        if(ind == n){
            return 0;
        }

        if(dp[ind][mask] != 1e9) return dp[ind][mask];
        
        ll res = 1e9;
        for(ll j = 0; j<n; j++){
            if((mask & (1<<j)) == 0){
                // if the jth bit is not set, then this jth element from nums2 can be picked up
                // setting the jth bit
                ll newmask = (mask | (1<<j)) ;
                res = min(res, (nums1[ind] ^ nums2[j]) + f(ind+1, newmask, nums1, nums2, dp));
            }
        }

        return dp[ind][mask] = res;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size();
        // dp[i][mask] : we are at the index i, and mask represents the elements of nums2 that have already been picked up

        // transition : 
        // for every bit in mask, if bit == 0 (element hasnt been picked up, so match it with the ith element of nums1)
        // dp[i][mask] = dp[i+1][turn the jth bit on in the mask] + nums1[i] ^ nums2[j]

        // base case : dp[n][all] = 0
        // final subproblem : dp[0][0]

        vector<vector<ll>> dp(n+1, vector<ll> (32000, 1e9));

        return f(0, 0, nums1, nums2, dp);
    }
};