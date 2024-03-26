using ll = long long;
class Solution {
public:
    int jump(vector<int>& nums) {
        ll n = nums.size();
        vector<ll> dp(n, INT_MAX);
        dp[n-1] = 0;
        for(ll i = n-2; i>=0; i--){
            for(ll j = 1; i+j<n && j<=nums[i]; j++){
                // valid step
                dp[i] = min(dp[i], 1 + dp[i+j]);
            }
        }
        return dp[0];
    }
};