class Solution {
private:
    bool dfs(int mineffort, int row, int col, vector<vector<int>>& heights, int patheffort, vector<vector<bool>>& vis){
        int n = heights.size();
        int m = heights[0].size();
        
        if(row<0 || row>=n || col<0 || col>=m) return false;
        if(patheffort > mineffort) return false;
        if(vis[row][col]) return false;

        if(row == n-1 && col == m-1) return true;

        vis[row][col] = true;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for(int i = 0; i<4; i++){
            int newr = row + dr[i];
            int newc = col + dc[i];

            if(newr>=0 && newr<n && newc>=0 && newc<m){
                int neweffort = abs(heights[row][col] - heights[newr][newc]);
                int currpatheffort = max(patheffort, neweffort);

                if(dfs(mineffort, newr, newc, heights, currpatheffort, vis)) return true;
            }
        }
        return false;
    }

    bool isPathPossible(int mineffort, int row, int col, vector<vector<int>>& heights){
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        return dfs(mineffort, row, col, heights, 0, vis);
    }

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // solution 2 : using binary search on range + dfs
        int n = heights.size();
        int m = heights[0].size();

        int low = 0, high = (int)1e6;
        int mid = low + (high-low)/2;

        int ans = -1;
        while(low <= high){
            mid = low + (high-low)/2;
            if(isPathPossible(mid, 0, 0, heights)){
                // if a path with "mid" effort is possible
                // then search for a smaller answer
                // and update ans
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};