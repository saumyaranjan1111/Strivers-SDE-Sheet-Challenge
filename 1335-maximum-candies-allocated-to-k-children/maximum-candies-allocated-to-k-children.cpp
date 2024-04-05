using ll = long long;
class Solution {
public:
    bool check(vector<int>&candies, ll k, ll mid){
        // how many subpiles of atleast size mid can be formed from the piles
        // if no >= k return true, else false
        ll piles = 0;
        for(auto x : candies){
            piles += x/mid;
        }
        return piles >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        // as k is fixed, if it is possible to give x candies to all the k children, then we can also give x-1 candies to them
        // monotonic function based on the number of candies that can be given to the children, find the last true : if true is defined by whether we can give the children some i candies : if yes : then True, if no then false
        ll low = 1, high = 1e9;
        ll ans = 0;
        while(low <= high){
            ll mid = low + (high-low)/2;
            if(check(candies, k, mid)){
                // we mid can be given to the each child, then check for bigger values
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }
};