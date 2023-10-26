class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<pair<int, int>, int>> q;
        if(grid[0][0] == 0)
        q.push({{0, 0}, 0});

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0] = true;

        while(!q.empty()){
            auto cell = q.front();
            int row = cell.first.first;
            int col = cell.first.second;
            int level = cell.second;

            if(row == n-1 && col == n-1){
                return level+1;
            }
            q.pop();

            int dr[] = {-1, 0, 1};
            int dc[] = {-1, 0, 1};

            for(int i = 0; i<3; i++){
                int newr = row+dr[i];
                for(int j = 0; j<3; j++){
                    int newc = col+dc[j];

                    if(newr>=0 && newr<n && newc>=0 && newc<n && vis[newr][newc]==false && grid[newr][newc] == 0){
                        // we are reaching this grid[newr][newc] for the first time ever, and hence this level at which we have reached this cell is the mini distance that it takes to reach this cell
                        vis[newr][newc] = true;
                        q.push({{newr, newc}, level+1});
                    }

                }
            }
        }
        return -1;
    }
};