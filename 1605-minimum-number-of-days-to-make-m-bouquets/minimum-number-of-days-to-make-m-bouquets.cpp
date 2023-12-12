#define ll long long
class Solution {
public:
    bool check(int mid, vector<int>& days, int m, int k){
        // does this array have m or more subarrays (non overlapping) within it, all having maximum values <= mid
        // if yes return true, else false
        int n = days.size();
        int count = 0;
        int l = 0, r = 0;
        priority_queue<int> q;

        while(l <= r && r<n){
            if(days[r] > mid){
                r++;
                l = r;
                continue;
            }

            // grow
            while(r<n && days[r] <= mid){
                if(l + k == r) break;
                
                q.push(days[r]);
                r++;
            }

            if(l + k == r){
                // valid window, so now search from the end of the valid window
                count++;
                l = r;
            }
            else {
                // invalid window, start shrinking from the left side until you find the element which was > mid
                while(!q.empty() && q.top() > mid){
                    q.pop();
                    l++;
                }
            }
        }

        if(count >= m) return true;
        return false;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        ll n = bloomDay.size();
        if((ll)m*k > n){
            // no of reqd flowers > available
            return -1;
        }

        int maxi = bloomDay[0];
        int mini = bloomDay[0];
        for(int i = 1; i<n; i++){ 
            maxi = max(maxi, bloomDay[i]);
            mini = min(mini, bloomDay[i]);
        }
        // on day maxi, all flowers would have already bloomed
        // so maxi is an answer, but we can do better than this
        // binary search on answer as we can always make more bouquets if we wait for more days : monotonic
        // there will be a lower limit of days below which we will not be able to make all the bouquets
        // that limit is the answer
        int low = mini, high = maxi;
        // the lowest answer could be the earliest day, because we'll not be able tomake any bouquets if we dont wait for even a single rose to bloom

        int mid = low + (high - low)/2;
        int ans = -1;
        while(low <= high){
            mid = low + (high - low)/2;

            // check if we can make m bouquets in mid no of days, if yes then check for less
            // if no, then check for more

            if(check(mid, bloomDay, m, k)){
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};