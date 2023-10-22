class Solution {
private:
    void bfs(int root, vector<vector<int>>& isConnected, vector<bool>& vis){
        int n = vis.size();

        queue<int> q;
        q.push(root);
        vis[root] = true;

        while(!q.empty()){
            auto root = q.front();
            q.pop();

            for(int i = 0; i<n; i++){
                if(isConnected[root][i] == 1 && vis[i] == false && i != root){
                    q.push(i);
                    vis[i] = true;
                }
            }
        }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i<n; i++){
            if(visited[i] == false){
                bfs(i, isConnected, visited);
                count++;
            }
        }
        return count;
    }
};