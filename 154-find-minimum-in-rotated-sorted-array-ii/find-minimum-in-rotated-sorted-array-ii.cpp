using ll = long long;
class Solution {
public:
    int findMin(vector<int>& nums) {
        ll n = nums.size();
        ll mini = INT_MAX;
        ll left = 0, right = n-1;
        while(left <= right){
            ll mid = left + (right-left)/2;
            mini = min(mini, (ll)nums[mid]);
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                left++;
            } else {
                if(nums[mid] >= nums[left]){
                    mini = min(mini, (ll)nums[left]);
                    left = mid+1;
                } else if(nums[mid] <= nums[right]){
                    mini = min(mini, (ll)nums[mid]);
                    right = mid-1;
                }   
            }
        }
        return mini;
    }
};