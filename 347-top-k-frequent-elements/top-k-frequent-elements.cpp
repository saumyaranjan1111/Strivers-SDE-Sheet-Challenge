class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(auto x : nums) mp[x]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it = mp.begin(); it!=mp.end(); it++){
            if(pq.size() < k){
                pq.push({it->second, it->first});
            } else {
                if(it->second > pq.top().first){
                    pq.push({it->second, it->first});
                    pq.pop();
                }
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};