class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ogcolor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

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

                if((newr >= 0 && newr < n) && (newc >= 0 && newc < m) && image[newr][newc] == ogcolor && image[newr][newc] != color){
                    q.push({newr, newc});
                    image[newr][newc] = color;
                }
            }
        }

        return image;
    }
};