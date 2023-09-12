class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; int j = 1;

        while(j<nums.size()){

            while(j<nums.size() && nums[i] == nums[j]) j++;
            if(j>=nums.size()) break;
            nums[i+1] = nums[j];
            i++;
            j++;
            while(j<nums.size() && nums[j] == nums[j-1]) j++;

        }
        return i+1;
    }
};