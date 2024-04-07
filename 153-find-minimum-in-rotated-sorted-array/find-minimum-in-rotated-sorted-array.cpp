using ll = long long;
class Solution {
public:
    int findMin(vector<int>& nums) {
        ll n = nums.size();
        ll low = 0, high = n-1;
        ll mid = high/2;
        ll ans = 0;
        while(low <= high){
            mid = low + (high-low)/2;
            if(nums[mid] > nums[n-1]){
                low = mid+1;
            } else {
                ans = mid;
                high = mid-1;
            }
        }
        return nums[ans];
    }
};