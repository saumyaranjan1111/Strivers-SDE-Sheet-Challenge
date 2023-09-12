class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, (int)1e8);

        dp[n-1] = 0;
        for(int i = n-2; i>=0; i--){
            
            for(int step = 1; step<= nums[i] && (i + step) < n; step++){
                dp[i] = min(dp[i] , 1 + dp[i + step]);
            }
        }
        return dp[0];
    }
};