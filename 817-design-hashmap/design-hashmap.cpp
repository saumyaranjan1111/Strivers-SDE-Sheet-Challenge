class MyHashMap {
    vector<int> mp;
public:
    MyHashMap() {
        mp = vector<int> (1e6 + 1, -1);
    }
    
    void put(int key, int value) {
        mp[key] = value;
    }
    
    int get(int key) {
        if(key<mp.size()){
            return mp[key];
        }
        else{
            return -1;
        }
    }
    
    void remove(int key) {
        if(key < mp.size()){
            mp[key] = -1;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */