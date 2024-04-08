using ll = long long;
class Solution {
public:
    int findMin(vector<int>& nums) {
        ll n = nums.size();
        ll left = 0, right = n-1;
        ll ans = INT_MAX;
        while(left <= right){
            ll mid = left + (right-left)/2;
            ans = min(ans, (ll)nums[mid]);

            if(nums[mid] <= nums[right]){
                right = mid-1;
            } else{
                left = mid+1;
            }
        }
        return ans;
    }
};