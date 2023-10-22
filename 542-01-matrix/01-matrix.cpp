class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
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

                if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc] == false){
                    vis[newr][newc] = true;
                    result[newr][newc] = min(result[newr][newc], t + 1);
                    q.push({{newr, newc}, t+1});
                }
            }
        }
        return result;
    }
};