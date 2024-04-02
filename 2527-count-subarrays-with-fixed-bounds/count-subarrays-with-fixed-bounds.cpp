using ll = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll maxi = -1, mini = -1;
        ll count = 0;
        ll n = nums.size();
        ll last = n;
        for(ll i = n-1; i>=0; i--){
            if(nums[i] < minK || nums[i] > maxK){
                // new boundary
                last = i;
                mini = -1; 
                maxi = -1;
                continue;
            }

            if(nums[i] == minK){
                mini = i;
            }
            if(nums[i] == maxK){
                maxi = i;
            }

            if(nums[i] == minK){
                if(maxi != -1)
                count += last - maxi;
            } else if(nums[i] == maxK){
                if(mini != -1)
                count += last - mini;
            } else {
                // mid value
                if(maxi != -1 && mini != -1)
                count += last - max(maxi, mini);
            }
        }
        return count;
    }
};