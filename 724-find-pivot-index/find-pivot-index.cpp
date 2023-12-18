class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+2, 0);
        prefix[1] = nums[0];
        for(int i = 1; i<n; i++) prefix[i+1] = prefix[i] + nums[i];

        int total = prefix[n];
        for(int i = 0; i<n; i++){
            int lsum = prefix[i];
            int rsum = total - prefix[i] - nums[i];
            if(lsum == rsum) return i;
        }
        return -1;

    }
};