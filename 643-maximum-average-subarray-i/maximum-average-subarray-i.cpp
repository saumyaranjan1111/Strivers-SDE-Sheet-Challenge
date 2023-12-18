class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxi = -1e4;
        int l = 0, r = k;
        double curr = 0;
        for(int i = l; i<r; i++){
            curr += nums[i];
        }
        curr /= k;
        maxi = max(maxi, curr);
        for(; r<n; r++, l++){
            curr-= (double)nums[l]/(double)k;
            curr+= (double)nums[r]/(double)k;
            maxi = max(maxi, curr);
        }

        return maxi;
    }
};