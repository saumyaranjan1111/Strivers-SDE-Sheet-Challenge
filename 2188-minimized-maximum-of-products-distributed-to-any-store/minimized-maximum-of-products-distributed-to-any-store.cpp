using ll = long long;
class Solution {
public:
    bool check(int n, vector<int>& quantities, ll mid){
        ll req = 0;
        for(auto x : quantities){
            req += ceil((double)x/mid);
        }

        return req <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        // if the answer is x, then any y>x is also a valid distribution
        // monotonic : predicate function : FFFFFTTTTT
        // find the first true
        ll low = 1, high = 1e5;
        ll ans = high;
        while(low <= high){
            ll mid = low + (high-low)/2;

            if(check(n, quantities, mid)){
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};