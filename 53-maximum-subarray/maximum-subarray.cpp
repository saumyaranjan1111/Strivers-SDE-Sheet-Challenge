class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // vector<int> maxsumtill(n+1, 0);
        // vector<int> prefix(n+1, 0);
        // prefix[0] = 0;
        // for(int i = 1; i<=n; i++){
        //     prefix[i] = prefix[i-1] + nums[i-1];
        // }
        // maxsumtill[i] = max(prefix[i] - prefix[j]), 0<=j<=i == prefix[i] - min(prefix[j]), 0<=j<=i
        int prev = 0;
        int mint = 0;
        int ans = -1e9;
        for(int i = 1; i<=n; i++){
            int curr = prev + nums[i-1];
            prev = curr;
            ans = max(ans, curr - mint);
            mint = min(curr, mint);
        }
        return ans;
    }
};