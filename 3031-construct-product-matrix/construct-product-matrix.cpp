#define ll long long
#define mod 12345
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<ll> up(n, 0);
        vector<ll> down(n, 0);
        ll prev = 1;
        for(int i = 0; i<n; i++){
            ll product = prev;
            for(int j = 0; j<m; j++){
                product = ((product % mod) * (grid[i][j] % mod))%mod; 
            }
            up[i] = product;
            prev = product;
        }

        // for(int i = 0; i<n; i++){
        //     cout<<up[i]<<endl;
        // }

        ll next = 1;
        for(int i = n-1; i>=0; i--){
            ll product = next;
            for(int j = 0; j<m; j++){
                product = ((product % mod) * (grid[i][j] % mod))%mod;
            }
            down[i] = product;
            next = product;
        }

        // for(int i = 0; i<n; i++){
        //     cout<<down[i]<<endl;
        // }

        vector<vector<vector<ll>>> leftright(n, vector<vector<ll>>(2, vector<ll>(m, 0)));

        for(int i = 0; i<n; i++){
            vector<ll> &left = leftright[i][0];
            vector<ll> &right = leftright[i][1];

            left[0] = grid[i][0];
            right[m-1] = grid[i][m-1];

            for(int j = 1; j<m; j++){
                left[j] = ((left[j-1]%mod) * (grid[i][j]%mod))%mod;
            }
            for(int j = m-2; j>=0; j--){
                right[j] = ((right[j+1]%mod) * (grid[i][j]%mod))%mod;
            }

            // for(int j = 0; j<m; j++){
            //     cout<<left[j]<<" ";
            // }
            // cout<<endl;
            // for(int j = 0; j<m; j++){
            //     cout<<right[j]<<" ";
            // }
            // cout<<endl;
        }

        vector<vector<int>> prod(n, vector<int> (m, 0));

        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){

                int upp, downn, leftt, rightt;

                upp = (i-1)>=0 ? up[i-1]%mod : 1;
                downn = (i+1)<=n-1 ? down[i+1]%mod : 1;
                leftt = (j-1)>=0 ? leftright[i][0][j-1]%mod : 1;
                rightt = (j+1)<=m-1 ? leftright[i][1][j+1]%mod : 1;
                

                prod[i][j] = ((upp%mod * downn%mod)%mod * (leftt%mod * rightt%mod)%mod)%mod;
            }
        }

        return prod;
    }
};