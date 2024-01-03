using ll = long long;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        ll l = 0, r = 0, n = nums.size();
        ll len = INT_MAX;
        ll sum = 0;
        while(r < n && sum < target){
            sum += nums[r];
            r++;
        }
        if(sum >= target)
        len = min(len, r - l);

        while(true){
            while(l<=r && sum >= target){
                len = min(len, r - l);
                sum -= nums[l];
                l++;
            }
            
            if(r == n) break;

            while(r<n && sum < target){
                sum += nums[r];
                r++;
            }
        }

        return len == INT_MAX ? 0 : (int)len;
    }
};