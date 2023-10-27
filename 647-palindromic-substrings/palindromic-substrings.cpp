class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, false));
        for(int i = 0; i<n; i++) dp[i][i] = true;

        for(int i = n-2; i>=0; i--){
            for(int j = i+1; j<n; j++){
                if(s[i] == s[j]){
                    if(j == i+1) dp[i][j] = true;
                    else
                    dp[i][j] = dp[i+1][j-1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        int total = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                total+=dp[i][j];
            }
        }
        return total;
    }
};