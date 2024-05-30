class Solution {
public:
    int f(int ind, int mask, vector<vector<int>> &dp, int n){
        if(ind == n){
            // if all n numbers have been picked -> valid arrangment
            if(mask + 1 == (1<<n)) return 1;
            return 0;
        }

        if(dp[ind][mask] != -1) return dp[ind][mask];

        int ans = 0;
        for(int j = 0; j<n; j++){
            // if the j+1 hasnt been picked and either j+1 % i+1 == 0 or vice versa
            if(((mask & (1<<j)) == 0) && (((ind+1) % (j+1) == 0) || ((j+1) % (ind+1) == 0))){
                ans += f(ind+1, mask + (1<<j), dp, n);
            }
        }

        return dp[ind][mask] = ans;
    }
    int countArrangement(int n) {
        // brute force would be O(n!) which would give tle since O(15!) = 1e13

        // state : dp[i][mask] : no of beautiful permutations from i->n-1 if mask represents the nos that have already been chosen in the permutation

        // transition : ans = sum(dp[i+1][mask + (1<<j)]), where ((j<<1) & mask == 0)
        // and (i+1 % j+1 == 0 || j+1 % i+1 == 0)

        // base case : dp[n][mask == (1<<n)]
        // final subproblem : dp[0][0]

        vector<vector<int>> dp(n, vector<int> ((1<<n), -1));

        return f(0, 0, dp, n);
    }
};