class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // solution 2 : floyd warshall : multisources shortest path between any two pair of nodes

        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            dp[u][v] = wt;
            dp[v][u] = wt;
        }
        for(int i = 0; i<n; i++){
            dp[i][i] = 0;
        }

        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(dp[i][k] == INT_MAX || dp[k][j] == INT_MAX){
                        continue;
                    }

                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        int mincount = INT_MAX;
        vector<int> counts(n);
        for(int i = 0; i<n; i++){
            int count = 0;
            for(int j = 0; j<n; j++){
                if(dp[i][j] <= distanceThreshold){
                    count++;
                }
            }
            mincount = min(mincount, count);
            counts[i] = count;
        }

        int ans;
        for(int i = 0; i<n; i++){
            if(counts[i] == mincount) ans = i;
        }

        return ans;


    }
};