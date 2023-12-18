class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n= nums.size();
        int maxi = 0;
        int curr = 0;

        int l = 0, r = 0;
        int zcount = 0;
        
        while(true){
            while(r < n && zcount < 2){
                if(nums[r] == 0) zcount++;
                r++;
            }

            if(zcount == 2){
                maxi = max(maxi, r - l - 2);
            }

            while(l<r && zcount > 1){
                if(nums[l] == 0) zcount--;
                l++;
            }

            maxi = max(maxi, r - l - 1);
            if(r == n) break;    
        }

        return maxi;
    }
};