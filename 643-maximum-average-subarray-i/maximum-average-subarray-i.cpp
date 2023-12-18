class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int maxsum = INT_MIN;
        int curr = 0;
        for(int i = 0; i<k; i++){
            curr+=nums[i];
        }
        maxsum = max(maxsum , curr);
        int l = 0, r = k;
        for(; r<n; r++, l++){
            curr -= nums[l];
            curr += nums[r];
            maxsum = max(maxsum, curr);
        }

        return (double)maxsum / (double)k;
    }
};