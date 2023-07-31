class Solution {
public:

    bool solve(int ind, vector<int>&arr, vector<int>&dp){
        if(ind >= arr.size() || ind<0){
            return false;
        }
        if(arr[ind] == 0) return true;
        if(arr[ind] < 0) return false;

        if(dp[ind] != -1) return dp[ind];
        // mark as visited
        arr[ind] = -arr[ind];
        bool ahead = solve(ind+arr[ind], arr, dp);

        bool backwards = solve(ind-arr[ind], arr, dp);
        arr[ind] = -arr[ind];

        return dp[ind] = (ahead || backwards);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> dp(arr.size(), -1);
        return solve(start, arr, dp);
    }
};