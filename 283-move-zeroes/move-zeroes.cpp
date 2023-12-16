class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();

        while(r<n && nums[r] != 0) {
            l++; r++;
        }

        while(r < n){

            while(r<n && nums[r] == 0) r++;
            if(r<n) swap(nums[l] , nums[r]);
            while(l<n && nums[l] != 0) l++;
        }
        
    }
};