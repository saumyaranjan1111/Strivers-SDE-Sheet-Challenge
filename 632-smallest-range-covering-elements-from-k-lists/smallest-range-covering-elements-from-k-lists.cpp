class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<pair<int, int>> newnums;
        set<pair<int, int>> st;
        for(int i = 0; i<nums.size(); i++){
            vector<int> &x = nums[i];
            for(auto &y: x){
                st.insert({y, i});
            }
        }

        for(auto it = st.begin(); it!= st.end(); it++){
            newnums.push_back({*it});
        }

        int n = newnums.size();
        int range = newnums[newnums.size()-1].first - newnums[0].first;
        pair<int, int> ans = {newnums[0].first, newnums[n-1].first};
        int l = 0, r = 0;
        map<int, int> indset;
        while(l<n){
            while(r<n && indset.size() < k){
                indset[newnums[r].second]++;
                r++;
            }

            if(indset.size() == k && newnums[r-1].first - newnums[l].first < range){
                range = newnums[r-1].first - newnums[l].first;
                ans.first = newnums[l].first;
                ans.second = newnums[r-1].first;
            }

            indset[newnums[l].second]--;
            if(indset[newnums[l].second] == 0)
            indset.erase(newnums[l].second);

            l++;
        }

        vector<int> res;
        res.push_back(ans.first);
        res.push_back(ans.second);

        return res;
    }
};