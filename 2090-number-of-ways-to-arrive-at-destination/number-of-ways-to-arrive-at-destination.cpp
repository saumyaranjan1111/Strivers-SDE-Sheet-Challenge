#define mod (long long)(1e9 + 7)
class Solution {
public:
    int countPaths(long long n, vector<vector<int>>& roads) {
        vector<long long> visited(n, false);
        vector<long long> dist(n, LONG_LONG_MAX);
        // count will store the no of ways to reach the nodes
        vector<long long> count(n, 0);
        // since 0 is the starting node, there is only one way to reach it
        count[0] = 1;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater <pair<long long, long long>> > pq;
        // push{0, 0} long longhe priority queue
        pq.push({0, 0});
        dist[0] = 0;

        vector<vector<pair<long long, long long>>> graph(n);
        for(auto road : roads){
            long long u = road[0];
            long long v = road[1];
            long long wt = road[2];

            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }
        while(!pq.empty()){
            // extract the node
            auto temp = pq.top(); pq.pop();
            long long node = temp.second;
            long long pathwt = temp.first;
            
            // if the node has already been taken out of the pq once before this, then that means that the path value with which it was taken out before was lesser (as such is the working of the priority queue)
            // no need to process this node again, as we would have already processed all the optimal paths going through this node in the that first iteration when this node was taken out of the pq itself
            if(visited[node]) continue;

            // mark node as visited
            visited[node] = true;
            
            for(auto child : graph[node]){
                long long cnode = child.first;
                long long edgewt = child.second;

                if(pathwt + edgewt < dist[cnode]){
                    // we found a new mincost path, so the no of ways of reaching this path would be equal to the no of ways of reaching the parent node
                    dist[cnode] = pathwt + edgewt;
                    pq.push({pathwt+edgewt, cnode});
                    count[cnode] = count[node];
                }
                else if(pathwt + edgewt == dist[cnode]){
                    // we came to cnode via a different path, but this time the cost is the same as it was when we can to the cnode using a different path earlier, so the no of ways to come to cnode would be the no of ways to arrive at cnode until now + the no of ways from this current path
                    // the no of ways from this current path = count[node]
                    count[cnode] = (count[cnode]%mod + count[node]%mod)%mod;
                    pq.push({pathwt+edgewt, cnode});
                }
            }
        }

        if(count[n-1] == LONG_LONG_MAX) return -1;
        return (int)count[n-1];
    }
};