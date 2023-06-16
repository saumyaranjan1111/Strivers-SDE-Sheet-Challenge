class Solution {
public:
    bool targetsum(vector<int>& nums, int ind, int target, vector<vector<int>>& dp)
    {
        // base cases
        // result base case:
        if(target==0) return true;
        if(target<0) return false;

        // invalid base case: to return if we are at a dead end
        if(ind == nums.size())
        {
            if(target==0) return true;
            else return false;
        }

        if(dp[ind][target] != -1) return dp[ind][target];

        // can target be achieved in the array[ind->n-1]
        // can target be achieved in the array[ind+1->n-1]

        // take
        bool take = targetsum(nums, ind+1, target-nums[ind], dp);
        
        // not take
        bool nottake = targetsum(nums, ind+1, target, dp);

        return dp[ind][target] = take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto e:nums)
        {
            sum+=e;
        }
        if(sum%2!=0) return false;
        sum = sum/2;
        // target-> sum->0 : size = sum+1
        // ind-> 0 to nums.size()-1 : size = nums.size()

        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return targetsum(nums, 0, sum, dp);
    }
};