class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> all;
        for(auto x: nums){
            for(auto y: x){
                all.push_back(y);
            }
        }
        vector<int> ans;
        sort(all.begin(), all.end());
        int range = all[all.size()-1] - all[0];
        pair<int, int> curr = {all[all.size()-1], all[0]};

        for(int i = 0; i<all.size(); i++){
            int low = all[i];
            int high = low;
            bool flag = true;
            for(int j = 0; j<nums.size(); j++){
                if(high - low >= range) break;
                vector<int> &arr = nums[j];
                int ind = lower_bound(arr.begin(), arr.end(), low) - arr.begin();
                
                if(ind == arr.size()){
                    flag = false;
                    break;
                } else {
                    high = max(high, arr[ind]);
                }
            }

            if(!flag) break;
            if(high - low < range){
                range = high - low;
                curr = {low , high};
            }
        }
        ans.push_back(curr.first);
        ans.push_back(curr.second);
        return ans;
    }
};