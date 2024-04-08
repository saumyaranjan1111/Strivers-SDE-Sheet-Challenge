using ll = long long;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        ll n = nums.size();
        ll left = 0, right = n-1;
        while(left <= right){
            ll mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[left]){
                if(nums[left] <= target &&  target <= nums[mid]){
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else {
                if(nums[mid] <= target && target <= nums[right]){
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};