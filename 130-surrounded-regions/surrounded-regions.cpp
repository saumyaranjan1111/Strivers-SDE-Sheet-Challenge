class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            if(board[i][0] == 'O'){
                vis[i][0] = true;
                q.push({i, 0});
            }
            if(board[i][m-1] == 'O'){
                vis[i][m-1] = true;
                q.push({i, m-1});
            }
        }

        for(int j = 0; j<m; j++){
            if(board[0][j] == 'O'){
                vis[0][j] = true;
                q.push({0, j});
            }
            if(board[n-1][j] == 'O'){
                vis[n-1][j] = true;
                q.push({n-1, j});
            }
        }

        while(!q.empty()){
            auto node = q.front();
            int row = node.first;
            int col = node.second;

            board[row][col] = '#';
            q.pop();

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};

            for(int i = 0; i<4; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr>=0 && newr<n && newc>=0 && newc < m && board[newr][newc] == 'O'){
                    q.push({newr, newc});
                    vis[newr][newc] = true;
                }
            }

        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};