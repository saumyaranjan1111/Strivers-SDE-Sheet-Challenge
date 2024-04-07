using ll = long long;
class Solution {
public:
    int findMin(vector<int>& nums) {
        ll n = nums.size();
        ll low = 0, high = n-1;
        ll ans = high;
        while(low <=high){
            ll mid = low + (high-low)/2;
            if(nums[mid] > nums[n-1]){
                low = mid+1;
            } else if(nums[mid] < nums[n-1]){
                ans = mid;
                high = mid-1;
            } else {
                // nums[mid] == nums[n-1]
                // whether to go left or to right
                if(nums[0] > nums[n-1]){
                    ans = mid;
                    high = mid-1;
                } else if(nums[0] < nums[n-1]){
                    ans = 0;
                    high = -1;
                } else {
                    while(low <= mid && nums[low] >= nums[mid]) {
                        low++;
                    }
                    if(low > high) break;
                    if(nums[low] < nums[mid]){
                        ans = low;
                        high = mid-1;
                    }
                }
            }
        }
        return nums[ans];
    }
};