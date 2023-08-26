class Solution {
public:
    void floodfill(vector<vector<int>>& image, int row, int col, int color, int curr)
    {
        int n = image.size();
        int m = image[0].size();

        if(row<0||row>=n||col<0||col>=m) return;
        
        // basically a way to mark visited
        if(image[row][col] == color) return;
        
        if(image[row][col] != curr) return;

        image[row][col] = color;

        floodfill(image, row-1, col, color, curr);
        floodfill(image, row, col-1, color, curr);
        floodfill(image, row+1, col, color, curr);
        floodfill(image, row, col+1, color, curr);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int curr = image[sr][sc];
        floodfill(image, sr, sc, color, curr);
        return image;
    }
};