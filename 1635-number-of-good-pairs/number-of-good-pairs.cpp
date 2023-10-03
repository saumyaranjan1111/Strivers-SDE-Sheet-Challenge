class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        map<int, int> mp;
        for(int i = 0; i<nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                count+= mp[nums[i]];
            }
            mp[nums[i]]++;
        }
        return count;
    }
};