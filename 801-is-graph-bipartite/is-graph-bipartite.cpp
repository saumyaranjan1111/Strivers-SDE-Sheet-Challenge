class Solution {
private:
    bool canColor(int root, vector<vector<int>>& graph){
        int col = 0;
        unordered_map<int, int> color;
        queue<pair<pair<int, int>, int>> q;
        q.push({{root, 0}, -1});
        color[root] = 0;

        while(!q.empty()){
            auto temp = q.front();
            int node = temp.first.first;
            int col = temp.first.second;
            int parent = temp.second;
            q.pop();

            for(auto child : graph[node]){
                if(child != parent){
                    if(color.find(child) != color.end()){
                        if(color[child] == col) return false;
                    }
                    else{
                        q.push({{child, !col}, node});
                        color[child] = !col;
                    }
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        for(int i = 0; i<n; i++){
            if(canColor(i, graph) == false) return false;
        } 
        return true;
    }
};