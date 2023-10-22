class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i<n; i++){
            if(grid[i][0] == 1){
                q.push({i, 0});
                grid[i][0] = 0;
            }
            if(grid[i][m-1] == 1){
                q.push({i, m-1});
                grid[i][m-1] = 0;
            }
        }
        for(int j = 0; j<m; j++){
            if(grid[0][j] == 1){
                q.push({0, j});
                grid[0][j] = 0;
            }
            if(grid[n-1][j] == 1){
                q.push({n-1, j});
                grid[n-1][j] = 0;
            }
        }

        while(!q.empty()){
            auto node = q.front();
            int row = node.first;
            int col = node.second;

            q.pop();

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            for(int i = 0; i<4; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr >=0 && newr<n && newc>=0 && newc<m && grid[newr][newc] == 1){
                    q.push({newr, newc});
                    grid[newr][newc] = 0;
                }
            }
        }

        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};