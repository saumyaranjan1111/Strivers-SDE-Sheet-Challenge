#define ll long long
class Solution {
public:
    bool possible(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost, ll mid){
        ll mincost = INT_MAX;

        for(int i = 0; i<composition.size(); i++){
            ll currcost = 0;
            for(int j = 0; j<composition[i].size(); j++){
                ll reqd = mid*composition[i][j];
                if(reqd > stock[j]){
                    // not enough stock of j type of metal is present to form mid no of alloys
                    ll extrareq = reqd - stock[j];
                    currcost += extrareq*cost[j];
                }
                else {
                    // enough stock present so we dont need to buy any extra stock
                    currcost += 0;
                    continue;
                }
            }
            mincost = min(mincost, currcost);
        }

        // mincost : minimum cost among all the machines to form mid no of alloys

        // if the minimum cost across all the machines to form mid no of alloys is less than the budget we have
        // then we can form mid no of alloys so return true
        // else return false;
        if(mincost <= budget) return true;
        return false;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        ll low = 0;
        ll high = (ll)1e9;

        ll mid = low + (high-low)/2;

        ll ans = 0;
        while(low <= high){
            mid = low + (high-low)/2;
            if(possible(n, k, budget, composition, stock, cost, mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return ans;
    }
};