class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n<=1) return 0; 

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i<n; i++){
            mp[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<bool> vis(n, false);
        vis[0] = true;
        vector<long long> dist(n, LONG_LONG_MAX);
        dist[0] = 0;

        while(!q.empty()){

            auto node = q.front();
            q.pop();
            
            long long val = node.first;
            long long level = node.second;

            if(val > 0 && vis[val-1] == false){
                q.push({val-1, level+1});
                dist[val-1] = min(dist[val-1], level+1);
                vis[val-1] = true;
            }
            if(val + 1<n && vis[val+1] == false){
                q.push({val+1, level+1});
                dist[val+1] = min(dist[val+1], level+1);
                vis[val+1] = true;
            }

            for(auto edge : mp[arr[val]]){
                if(vis[edge] == false){
                    q.push({edge, level + 1});
                    dist[edge] = min(dist[edge], level + 1);
                    vis[edge] = true;
                }
            }
            mp[arr[val]].clear();

        }
        return dist[n-1];
    }
};