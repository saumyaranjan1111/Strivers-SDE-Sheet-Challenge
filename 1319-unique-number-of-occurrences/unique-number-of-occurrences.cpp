class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        set<int> occur;
        unordered_map<int, int> mp;
        int n= arr.size();
        for(int i = 0; i<n; i++){
            mp[arr[i]]++;
        }
        for(auto it = mp.begin(); it!= mp.end(); it++){
            if(occur.find(it->second) != occur.end()){
                return false;
            }
            occur.insert(it->second);
        }
        return true;
    }
};