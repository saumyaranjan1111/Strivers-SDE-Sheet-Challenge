using ll = long long;
bool comp(const pair<ll, string> &a,const pair<ll, string> &b){
    return a.first < b.first;
}
class TimeMap {
public:
    unordered_map<string, vector<pair<ll, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end() || mp[key].size() == 0){
            return "";
        } 
        auto i = upper_bound(mp[key].begin(), mp[key].end(), make_pair((ll)timestamp, string()), comp) - mp[key].begin();
        i--;
        if(i>=0){
            return mp[key][i].second;
        } 
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */