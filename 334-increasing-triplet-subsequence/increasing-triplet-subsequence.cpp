class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxi(n);
        maxi[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            maxi[i] = max(maxi[i+1], nums[i]);
        }

        int mini = nums[0];
        for(int i = 1; i<n-1; i++){
            if(mini < nums[i] && nums[i] < maxi[i+1]) return true;

            mini = min(mini, nums[i]);
        }
        return false;
    }
};