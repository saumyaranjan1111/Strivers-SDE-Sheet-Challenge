class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        while(!q.empty()){
            auto node = q.front();
            int row = node.first.first;
            int col = node.first.second;
            int t = node.second;

            q.pop();

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};

            for(int i = 0; i<4; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr >=0 && newr <n && newc >=0 && newc <m && grid[newr][newc] == 1 && vis[newr][newc] != 2){
                    q.push({{newr, newc}, t+1});
                    vis[newr][newc] = 2;
                    time = max(time, t+1);
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] != 2){
                    return -1;
                }
            }
        }
        return time;
    }
};