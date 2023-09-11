class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // put all the vals at the end of the array by swapping
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1){
            if(val == nums[0]) {nums.pop_back();
            return 0;}
            else {
                return 1;
            }
        }

        int i = 0, j = n-1;
        while(j>=0 && nums[j] == val) {
            nums.pop_back(); j--;
        }

        while(i<n && nums[i] != val) i++;
        while(i<=j){
            if(nums[i] == val){
                if(nums[j] == val){
                    nums.pop_back();
                    j--;
                }
                else {
                    swap(nums[i], nums[j]);
                    nums.pop_back();
                    i++; j--;
                }
            }
            else {
                i++;
            }
        }
        return nums.size();
    }
};