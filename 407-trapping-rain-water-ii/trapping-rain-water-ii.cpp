class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // declaring a min heap  which will store the boundary heights with the least height at the top

        // our approach is to check if the weakest boundary can hold water from its neighbours
        // if the nbrs are on the boundary itself then no need to check since if the water can reach those nbrs(since they are at the boundary themselves), then the water can flow out from those nbrs only so no need to check for them
        // check for the nbrs of the current boundary cell which have not been visited yet and are not on the boundary of the grid
        // if the ht of the nbr is < current cells height, then the curent boundary cell can hold the water and since this is the weakest boundary cell out of all, the only possibility was that the water could flow from here only, and if the water cannot even flow from here, then there is nopossiblity of the water to flow from anywhere else in the grid
        // so make this nbr the new boundary and add the diff to the total volume
        // also, while adding the new nbr as part of the boundary, fill water into it and then add it to the pq to simulate the water being filled atleast to the level of the smallest boundary earlier to convey the information of what the lowest boundary was in the outer boundary layer

        // add all the boundary cells to the pq and mark them as visited
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){

                    pq.push({grid[i][j], {i, j}});
                    vis[i][j] = true;
                }
            }
        }

        int vol = 0;

        // now start by taking the min of the boundary cells
        while(!pq.empty()){
            auto curr = pq.top();
            auto curht = curr.first;
            int curri = curr.second.first;
            int currj = curr.second.second;
            pq.pop();

            // check its 4 neighbours
            vector<int> dr = {0,0,-1,1};
            vector<int> dc = {1,-1,0,0};

            for(int i = 0; i<4; i++){
                int nbri = curri + dr[i];
                int nbrj = currj + dc[i];

                if(nbri < n && nbri >=0 && nbrj < m && nbrj >= 0 && vis[nbri][nbrj] == false){
                    
                    if(grid[nbri][nbrj] >= curht){
                        // no volume will be added 
                        // just add the new cell to the boundary
                        pq.push({grid[nbri][nbrj], {nbri, nbrj}});
                        vis[nbri][nbrj] = true;
                        
                    }
                    else{
                        // this neighbour is having its value smaller than the current boudnary
                        // so the this cell will store water that is equal to the diff b/w its value and the current boundary
                        vol+= curht - grid[nbri][nbrj];

                        // now fill this cell with the diff and add this cell to the pq with this new height
                        pq.push({curht, {nbri, nbrj}});
                        vis[nbri][nbrj] = true;
                    }
                }
            }
            
        }
        return vol;
    }
};