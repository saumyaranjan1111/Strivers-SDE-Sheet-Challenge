class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
	// .......................DFS.............................
   bool dfs(vector<vector<int>> &grid,int r,int c,int i,int j,int val,vector<vector<bool>> &visit){
            if(i < 0 || j < 0 ||i >= r || j >= c || visit[i][j])
                    return false ;
            
            if(i == r-1 &&  j == c-1){
                    return grid[i][j] >= val;
            }
            
            visit[i][j] = true;
       
            
            for(int x = 0;x<4;x++){
                     int ni = i + dx[x];
                     int nj = j + dy[x];
      
                     if(grid[i][j] >= val && dfs(grid,r,c,ni,nj,val,visit)) return true;
            }
            return false;
   }    
        
    int maximumSafenessFactor(vector<vector<int>>& grid) {
            
           
            
            int r =  grid.size();
            int c = grid[0].size();
            queue<pair<int,int>> q;
            for(int i = 0;i<r;i++){
                    for(int j = 0;j<c;j++){
                            if(grid[i][j] == 1)
                                    q.push({i,j});
                    }
            }
             if(grid[0][0] == 1 || grid[r-1][c-1] == 1) return 0;
            //.................................BFS........................//
            while(!q.empty()){
                    int f = q.front().first;
                    int s = q.front().second;
                    int val = grid[f][s];
                    q.pop();
                    
                    for(int x = 0;x<4;x++){
                            int i = f + dx[x];
                            int j = s + dy[x];
                            if(i >= 0 && j >= 0 && i < r && j < c && grid[i][j] == 0){
                                    grid[i][j] = val + 1;
                                    q.push({i,j});
                            }else if(i >= 0 && j >= 0 && i < r && j < c){
                                    grid[i][j] = min(grid[i][j],val+1);
                            }
                    }
            }
            
            
            //..............................BINARY SEARCH...............//
            int ans = 0;
            int l = 0 , rr = 500;
            while(l <= rr){
            int mid = (l + rr) / 2;        
            vector<vector<bool>> visit(r,vector<bool>(c,false));
            if(dfs(grid,r,c,0,0,mid,visit))
                    ans = max(ans,mid),
                    l = mid + 1;
            else
                    rr = mid - 1;
            }
           
            return ans-1;
            
        
    }
};