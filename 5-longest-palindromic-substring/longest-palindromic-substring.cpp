class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen = 0;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
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

        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(dp[i][j]) maxlen = max(maxlen, j-i+1);
            }
        }
        string ans = "";
        // cout<<maxlen<<endl;
        for(int i = 0, j = maxlen-1; j<n; i++, j++){
            if(dp[i][j]){
                for(int k = i; k<=j; k++){
                    ans+=s[k];
                }
                    return ans;
            }
        }
        return ans;

    }
};