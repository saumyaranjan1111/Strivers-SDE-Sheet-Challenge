class Solution {
public:
    int jump(vector<int>& nums) {
        
        // state : dp[i] = min no of jumps required to reach n-1 from i
        // transition : 
        // dp[i] = infinity
        // for 1<=jump<=nums[i]
        // dp[i] = min(dp[i], 1 + dp[i+jump])
        // base case: dp[n-1] = 0

        // final subproblem : dp[0]

        vector<int> dp(nums.size(), 1e8);
        int n = nums.size();
        dp[n-1] = 0;
        for(int i = n-2; i>=0; i--){
            for(int jump = 1; jump<=nums[i]; jump++){
                if(i + jump<=n-1)
                dp[i] = min(dp[i], 1 + dp[i+jump]);
                else break;
            }
        }
        return dp[0];
    }
};