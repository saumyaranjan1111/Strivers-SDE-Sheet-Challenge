class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> temp = nums;
        int n= nums.size();
        bool flag1 = true;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            if(nums[i] != temp[i]){
                flag1 = false;
                break;
            }
        }
        bool flag2 = true;
        for(int i = n-1; i>=0; i--){
            if(nums[i] != temp[n-i-1]){
                flag2 = false;
                break;
            }
        }
        if(flag1 || flag2) return true;
        return false;
    }
};