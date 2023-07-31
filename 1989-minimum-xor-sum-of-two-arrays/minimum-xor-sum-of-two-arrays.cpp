#define ll long long
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        // if we try to use recursion to generate all the possible permutations then it wont work because n<=14 and 14! >= 10^11
        // so another option is dp with bitmasking because the constraints are small and recursion cant be used, therefore dp with bitmasking can be used in this case

        // state : suppose we are at the index i, and we have used some elements from 0 to i-1, we will now try to match all the remaining elements (which have not been matched until now) ans take the one which produces the minimum sum

        // dp[i][something to indicate which elements have already been picked][j] : min xor sum in i...n-1 if the jth element of the second array was matched with the ith element

        // transition : 
        // dp[i][mask] = for all js, if j has not been picked yet 
        //  min(nums1[i]^nums2[j] + dp[i+1][mask | 1<<j])

        // base case : dp[n][anything] = 0 
        // final subproblem : 
        // dp[0][0]

        ll n = nums1.size();
        ll maxmask = (1<<14);
        vector<vector<ll>> dp(n+1, vector<ll>(maxmask, INT_MAX));
        
        for(ll i = 0; i<maxmask; i++)
        {
            dp[n][i] = 0;
        }

        for(ll i = n-1; i>=0; i--){
            
            for(ll mask = 0; mask < maxmask; mask++)
            {
                ll ans = INT_MAX;
                for(ll j = 0; j<n; j++){

                    if(((1<<j)&mask) == 0){
                        ll nxt = (mask + (1<<j));
                        // ll currans = nums1[i]^nums2[j];
                        ll currans =  (nums1[i]^nums2[j]) + dp[i+1][nxt];
                        ans = min(ans, currans);
                    }
                }

                dp[i][mask] = ans;
            }
            
        }
        return dp[0][0];
    }
};