using ll = long long;
class Solution {
public:
    bool check(vector<int>& piles, int h, ll mid){
        ll hours = 0;
        for(auto x : piles){
            hours += ceil((double)x/mid);
        }

        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        ll n = piles.size();
        ll low = 1, high = 1e9;
        ll ans = high;
        while(low <= high){
            ll mid = low + (high - low)/2;
            if(check(piles, h, mid)){
                ans = mid; 
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};