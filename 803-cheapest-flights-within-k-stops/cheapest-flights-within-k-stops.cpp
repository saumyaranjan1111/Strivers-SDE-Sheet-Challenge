class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<vector<pair<int, int>>> graph(n);

        // make a graph
        for(auto edge : flights){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            graph[u].push_back({v, wt});
        }

        // make a priority queue of the form {dist, {node, stops}}
        
        set<pair<int, pair<int, int>>> st;
        st.insert({0, {src, 0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!st.empty()){
            auto temp = *(st.begin());
            int distance = temp.first;
            int parentnode = temp.second.first;
            int stops = temp.second.second;
            if(parentnode == dst) break;
            st.erase(st.begin());

            for(auto child : graph[parentnode]){
                int childnode = child.first;
                int edgewt = child.second;
                if(dist[childnode] > distance + edgewt && stops <= k){
                    dist[childnode] = distance + edgewt;
                    st.insert({dist[childnode], {childnode, stops+1}});
                }
                else if(stops <= k){
                    st.insert({distance + edgewt, {childnode, stops+1}});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;
        
        return dist[dst];
    }
};