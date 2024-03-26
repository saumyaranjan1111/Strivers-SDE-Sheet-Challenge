class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> mp;
        for(auto x: bills){
            if(x == 5){
                mp[5]++;
            } else if(x == 10){
                mp[10]++;
                if(mp.find(5) != mp.end()){
                    mp[5]--;
                    if(mp[5] == 0) mp.erase(5);
                } else {
                    return false;
                }
            } else {
                mp[20]++;
                if(mp.find(10) != mp.end() && mp.find(5) != mp.end()){
                    mp[10]--;
                    mp[5]--;
                    if(mp[5] == 0) mp.erase(5);
                    if(mp[10] == 0) mp.erase(10);
                } else if(mp.find(5) != mp.end() && mp[5] >= 3){
                    mp[5]-=3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};