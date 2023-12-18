class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0;
        map<vector<int>, int> mp;

        for(int i = 0; i<grid.size(); i++){
            vector<int> &row = grid[i];
            mp[row]++;
        }

        for(int j = 0; j<grid.size(); j++){
            vector<int> col;
            for(int i = 0; i<grid.size(); i++){
                col.push_back(grid[i][j]);
            }
            if(mp.find(col)!=mp.end()) {
                count += mp[col];
            }
        }

        return count;
    }
};