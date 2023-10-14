class Solution {
public:
    int solve(int ind, int remwalls, vector<pair<int, int>> &costime, vector<vector<int>> &dp){
        int n = costime.size();

        // no walls left to paint, so the cost of painting no walls would be 0,so return 0
        if(remwalls<=0) return 0;

        // out of bounds
        if(ind >= n) return (int)(1e9);


        if(dp[ind][remwalls] != -1) return dp[ind][remwalls];


// dont paint the current wall by the painter 1, so the remaining walls to be painted remain the same as before, and we go to the next wall
        int notPaintby1 = solve(ind+1, remwalls, costime, dp);

        // paint the current wall using the painter1, so the no of remaining walls to be painted are equal to the current walls - 1(the current wall becomes painted) - costime[ind].second(no of walls equal to the time of the current wall will get painted by the painter2 during the same time it took to paint the current wall by painter1)
        int paintby1 = costime[ind].first + solve(ind+1, remwalls - 1 - costime[ind].second, costime, dp);

        
        return dp[ind][remwalls] = min(notPaintby1, paintby1);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<pair<int, int> > costime;
        for(int i = 0; i<cost.size(); i++){
            costime.push_back({cost[i], time[i]});
        }
        sort(costime.begin(), costime.end());

        vector<vector<int>> dp(501, vector<int> (501, -1));
        return solve(0, cost.size(), costime, dp);
    }
};