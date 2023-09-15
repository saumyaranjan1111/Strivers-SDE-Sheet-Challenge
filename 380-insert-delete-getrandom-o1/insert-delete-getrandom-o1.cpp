class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> nums;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            // item not present 
            // insert item and return true
            nums.push_back(val);
            mp[val] = nums.size()-1;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            // val is present 
            int presentidx = mp.find(val)->second;
            mp[nums[nums.size() - 1]] = presentidx;
            swap(nums[nums.size() - 1], nums[mp.find(val)->second]);
            
            nums.pop_back();
            mp.erase(val);

            return true;
        }
        else {
            return false;
        }
    }
    
    int getRandom() {
        int random = rand();
        random = random%nums.size();
        return nums[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */