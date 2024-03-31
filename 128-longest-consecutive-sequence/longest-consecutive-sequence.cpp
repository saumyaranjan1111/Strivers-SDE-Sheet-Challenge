class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int i = 0; 
        while(i<n){
            int j = i+1;
            int dupli = 0;
            while(j<n){
                if(nums[j] == nums[j-1] + 1) j++;
                else if(nums[j] == nums[j-1]){
                    dupli++;
                    j++;
                } else {
                    break;
                }
            }
            ans = max(ans, j-i - dupli);
            i = j;
        }
        return ans;
    }
};