class Solution {
public:
    bool possible(int ind, vector<int>& nums, vector<int>& dp){
        if(ind >= nums.size()) return false;
        if(ind == nums.size() - 1) return true;

        if(dp[ind] != -1) return dp[ind];

        for(int i = 1; i<=nums[ind] ; i++){
            if(possible(ind+i, nums, dp)) return dp[ind] = true;
        }

        return dp[ind] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        if(possible(0, nums, dp)) return true;
        
        return false;
    }
};