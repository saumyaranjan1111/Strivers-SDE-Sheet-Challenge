class Solution {
public:
    long long dfs(int node, vector<bool>& primes, vector<int>& vis, vector<vector<int>>& adj, int &groupno){
        //this function marks all the nodes that are a part of the group b/w two prime nodes as the group no and also returns the count of all such nodes within that group 

        // if the node is already visited or the node is a prime then return 0;
        if(vis[node] != 0 || primes[node]) return 0;

        // since the current node is not visited and not a prime node, then mark the current node with the groupno
        // and count the nonprime nodes among the children
        vis[node] = groupno;
        long long count = 1;
        for(auto c: adj[node]){
            count+=dfs(c, primes, vis, adj, groupno);
        }
        return count;
    }
    long long countPaths(int n, vector<vector<int>>& edges) {
        
        // store all the primes upto n
        vector<bool> primes(n+1, true);
        for(int i = 2; i<=n; i++){
            if(primes[i] == false) continue;
            int j = 2;
            while(i*j <= n){
                primes[i*j] = false;
                j++;
            }
        }
        primes[0] = false;
        primes[1] = false;
        // make an undirected graph with the help of the edges
        vector<vector<int>> adj(n+1);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // return 0;
        vector<int> groupcount(n+1, 0);
        int groupno = 1;
        vector<int> vis(n+1, 0);
        for(int i = 1; i<=n; i++){
            groupcount[groupno++] = dfs(i, primes, vis, adj, groupno);
        }
        
        // for(int i = 1; i<groupcount.size(); i++){
        //     cout<<groupcount[i]<<" ";
        // }
        // cout<<endl;

        long long ans = 0;
        for(int i = 2; i<=n; i++){
            if(primes[i]){

                long long total = 0;
                vector<int> individualpathcounts;
                for(auto c: adj[i]){
                    // total no of nodes in this current group that the child c belongs to 
                    
                    total += groupcount[vis[c]];
                    individualpathcounts.push_back(groupcount[vis[c]]);
                }

                long long paths = 0;
                for(auto v: individualpathcounts){
                    paths += ((total - v) * v);
                }
                paths = paths/2;
                paths += total;

                ans+=paths;

            }
        }
        return ans;
    }
};