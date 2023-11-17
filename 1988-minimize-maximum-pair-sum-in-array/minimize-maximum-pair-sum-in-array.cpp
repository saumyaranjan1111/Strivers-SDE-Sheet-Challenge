class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxi = 0;
        int n = nums.size();
        for(int i = 0, j = n-1; i<j; i++, j--){
            maxi = max(nums[i] + nums[j], maxi);
        }
        return maxi;
    }
};