#define ll long long
#define mod (int)(1e9 + 7)

class Solution {
public:
    int knightDialer(int n) {
        vector<vector<vector<ll>>> dp(4, vector<vector<ll>>(3, vector<ll>(n, 0)));
        // ll dp[4][3][n] = {0};
        // dp[r][c][x] : the no of numbers possible having x length, if the knight is currently at position r, c

        // transition : dp[r][c][x] = sum(dp[allnewrows][allnewcols][x-1])
        // final subproblem : sum(dp[r][c][n-1]) where r : 0 to 3, and c from 0 to 2
        // base case : dp[3][0][any] = 0 and dp[3][2][any] = 0


        for(ll i = 0; i<4; i++){
            for(ll j = 0; j<3; j++){
                dp[i][j][0] = 1;
            }
        }

        for(ll x = 0; x<n; x++){
            dp[3][0][x] = 0;
            dp[3][2][x] = 0;
        }

        ll dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        ll dc[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for(ll k = 1; k<n; k++){
            for(ll i = 0; i<4; i++){
                for(ll j = 0; j<3; j++){ 
                    
                    if(i == 3 && (j == 0 || j == 2)){
                        dp[i][j][k] = 0;
                        continue;
                    }  

                    for(ll l = 0; l < 8; l++){
                        
                        ll newr = i + dr[l];
                        ll newc = j + dc[l];

                        if(newr>=0 && newr<4 && newc>=0 && newc<3 && !(newr == 3 && (newc == 0 || newc == 2))){
                            dp[i][j][k] = (dp[i][j][k]%mod + dp[newr][newc][k-1]%mod)%mod;
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(ll i = 0; i<4; i++){
            for(ll j = 0; j<3; j++){
                ans+=dp[i][j][n-1]%mod;
                ans = ans%mod;
                // cout<<dp[i][j][n-2]<<" ";
            }
            // cout<<endl;
        }

        return ans;

    }
};