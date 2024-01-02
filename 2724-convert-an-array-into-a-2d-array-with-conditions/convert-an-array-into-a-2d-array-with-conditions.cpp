class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // nlogn
        int n = nums.size();
        vector<vector<int>> ans;

        unordered_map<int, int> freq;
        int rows = 0;
        for(auto &x : nums){
            freq[x]++;
        }

        for(auto it = freq.begin(); it!= freq.end(); it++){
            rows = max(rows, it->second);
        }

        while(!freq.empty()){
            vector<int> temp;
            for(auto it = freq.begin(); it!= freq.end(); it++){
                if(it->second > 0){
                    temp.push_back(it->first);
                    it->second = it->second - 1;
                }
            }
            if(temp.size() == 0) break;
            ans.push_back(temp);
        }

        return ans;
    }
};