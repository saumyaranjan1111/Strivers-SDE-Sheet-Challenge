class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // using bfs
        
        // make a graph
        vector<vector<pair<int, int>>> graph(n);
        int m = flights.size();
        for(auto edge :flights){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            graph[u].push_back({v, wt});
        }

        // make a queue to store {stops, node, distance}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        // make a distance array
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // perform the algo
        while(!q.empty()){
            auto temp = q.front();
            int stops = temp.first;
            int node = temp.second.first;
            int distance = temp.second.second;
            q.pop();

            if(stops>k) break;

            for(auto child : graph[node]){
                int cnode = child.first;
                int edgewt = child.second;

                if(edgewt + distance < dist[cnode] && stops<=k){
                    // if the current path is the best path found till now and the stops are within limit, update the distance array and push the new path to cnode to the queue
                    dist[cnode] = edgewt+distance;
                    q.push({stops+1, {cnode, edgewt + distance}});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};