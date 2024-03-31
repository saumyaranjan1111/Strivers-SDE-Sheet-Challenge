class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_map<int, int> mp;
        for(auto x: nums){
            mp[x] = 1;
        }
        int ans = 1;
        for(auto x: nums){
            // we want to get to the starting element of the sequence
            // if x-1 is found then move on
            if(mp.find(x-1) != mp.end()) continue;
            else {
                // x-1 not found, this can be the start of a sequence
                // start counting
                int count = 1; 
                while(mp.find(x+1) != mp.end()){
                    count++;
                    x++;
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};