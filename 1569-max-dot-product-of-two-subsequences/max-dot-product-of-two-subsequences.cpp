class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        int ans = help(0, 0, a, b, n, m, dp);
        if(ans == 0) {
            int fmax = INT_MIN, fmin = INT_MAX, smax = INT_MIN, smin = INT_MAX;
            for(int i=0; i<n; i++) {
                 fmin = min(a[i], fmin);
                 fmax = max(a[i], fmax);
            }
            for(int i=0; i<m; i++) {
                 smin = min(b[i], smin);
                 smax = max(b[i], smax);
            }
            if((fmax<0 && smin>0) || (fmin>0 && smax<0)) {
                ans = max((fmax*smin), (fmin*smax));
            }
        }
        return ans;
    }

    int help(int i, int j, vector<int>& a, vector<int>& b, int n, int m,   vector<vector<int>>& dp) {
        if(i==n || j==m) {
            return 0;
        }
        if(dp[i][j] != INT_MIN) return dp[i][j];
        int opTake = a[i]*b[j]+(help(i+1, j+1, a, b, n, m, dp));
        int opI = help(i, j+1, a, b, n, m, dp);
        int opJ = help(i+1, j, a, b, n, m, dp);

        // int ans = INT_MIN;
        // ans=max(ans,opTake);
        // if(c==1) 
        return dp[i][j] = max(opTake, max(opI, opJ));
    }
};