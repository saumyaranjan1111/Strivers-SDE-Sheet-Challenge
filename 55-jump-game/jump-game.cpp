using ll = long long;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        ll n = nums.size();
        vector<bool> dp(n);
        dp[n-1] = true;
        ll lasttrue = n-1;
        for(ll i = n-2; i>=0; i--){
            if(lasttrue <= i+nums[i]){
                dp[i] = true;
                lasttrue = i;
            } else {
                dp[i] = false;
            }
        }
        return dp[0];
    }
};