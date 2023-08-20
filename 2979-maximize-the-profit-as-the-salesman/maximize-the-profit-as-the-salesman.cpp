class Solution {
public:
    int findJustBigHouse(vector<vector<int>>& offers, int i, int num){

        vector<int> temp;
        temp.push_back(num);
        temp.push_back(INT_MAX);
        temp.push_back(INT_MAX);

        return upper_bound(offers.begin(), offers.end(), temp) - offers.begin();
    }
    int solve(vector<vector<int>>& offers, int ind, vector<int>& dp){
        int m = offers.size();
        if(ind >= m) return 0;

        // we can either pick this current offer or not pick the current offer
        // if we dont pick the current offer then we can go to the next offer always, since we were able to come to this offer, the next offer will also be pickable

        if(dp[ind] != -1) return dp[ind];

        // dont pick
        int notpick = 0 + solve(offers, ind+1, dp);

        // if we pick this offer, we cant pick all the offers after this which have their starting house no < the current offers ending house no
        int pick = offers[ind][2];
        
        
        int i = findJustBigHouse(offers, ind+1, offers[ind][1]);

        if(i < m){
            pick += solve(offers, i, dp);
        }


        return dp[ind] = max(pick , notpick);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m = offers.size();
        sort(offers.begin(), offers.end());

        vector<int> dp(m, -1);
        return solve(offers, 0, dp);
    }
};