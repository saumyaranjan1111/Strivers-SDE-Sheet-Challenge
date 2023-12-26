#define ll long long
class Solution {
public:
    ll check(vector<int> &nums, ll mid){
        ll n = nums.size();
        // find the no of pairs in the array having diff <= mid
        ll count = 0;
        for(ll i = 0; i<n-1; i++){
            ll temp = upper_bound(nums.begin() + i, nums.end(), nums[i] + mid) - nums.begin();
            if(temp != n){
                if(nums[temp] - nums[i] > mid){
                    count += (temp - 1) - i;
                }
                else {
                    count += (temp) - i;
                }
            }
            else {
                count += (temp - 1) - i;
            }
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ll high = nums[n-1] - nums[0];

        ll low = high;
        for(int i = 0; i<n-1; i++){
            low = min(low, (ll)nums[i+1] - nums[i]);
        }

        ll ans = high;
        while(low<=high){
            ll mid = low + (high - low)/2;
            cout<<low<<" "<<high<<" "<<mid<<" "<<check(nums, mid)<<endl;
            // how many pairs have a diff <= mid
            // as we increase mid, the no of pairs having diff <= mid will increase
            // increasing function 
            // x : mid
            // y : pairs having diff <= mid
            // predicate : FFFFTTTT ( look for the first True value )
            if(check(nums, mid) < k){
                // pairs having diff<= mid are less than k, find a bigger mid
                low = mid+1;
            }
            else {
                // pairs having diff<= mid are >= k, for now this can be the answer, but try to find a smaller mid
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};