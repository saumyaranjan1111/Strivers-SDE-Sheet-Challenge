class Solution {
private: 
    vector<int> djikstra(vector<vector<pair<int, int>>> &graph, int s){
        int n = graph.size();
        vector<int> dist(n, INT_MAX);

        dist[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int pathdist = temp.first;
            int node = temp.second;

            for(auto child : graph[node]){
                int childnode = child.second;
                int edgewt = child.first;

                if(dist[childnode] > pathdist + edgewt){
                    dist[childnode] = pathdist + edgewt;
                    pq.push({dist[childnode] , childnode});
                }
            }
        }

        return dist;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // solution 1: using multinode djikstra
        // use djikstra from each node seperately, and then choose the city which can reach the least amount of cities from it

        // make a graph from the edges 
        vector<vector<pair<int, int>>> graph(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            graph[u].push_back({wt, v});
            graph[v].push_back({wt, u});
        }

        // create a n*n matrix which will contain the distance from all the nodes to all the other nodes
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        for(int i = 0; i<n; i++){
            distance[i] = djikstra(graph, i);
        }

        // citycount[i] : no of cities that the city i connects to within the thresholdDistance
        vector<int> citycount(n);

        for(int i = 0; i<n; i++){
            int count = 0;
            for(int j = 0; j<n; j++){
                if(distance[i][j] <= distanceThreshold){
                    count++;
                }
            }
            citycount[i] = count;
        }

        // find the minimum value from all such counts
        int minval = INT_MAX;
        for(int i = 0; i<n; i++){
            minval = min(minval, citycount[i]);
        }

        vector<int> answers;
        for(int i = 0; i<n; i++){
            if(minval == citycount[i]){
                answers.push_back(i);
            }
        }
        sort(answers.begin(), answers.end());
        return answers[answers.size()-1];
    }
};