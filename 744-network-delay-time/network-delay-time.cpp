class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        vector<int> dist(n+1, INT_MAX);
        for(auto edge : times){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            graph[u].push_back({v, wt});
        }

        priority_queue<pair<int, int>> pq;
        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            auto temp = pq.top();
            int pathwt = temp.first;
            int node = temp.second;

            pq.pop();

            for(auto child: graph[node]){
                int cnode = child.first;
                int edgewt = child.second;

                if(edgewt + pathwt < dist[cnode]){
                    // relax
                    dist[cnode] = edgewt + pathwt;
                    pq.push({edgewt + pathwt, cnode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i<=n; i++){
            ans = max(ans, dist[i]);
        }

        if(ans == INT_MIN || ans == INT_MAX) return -1;
        return ans;
    }
};