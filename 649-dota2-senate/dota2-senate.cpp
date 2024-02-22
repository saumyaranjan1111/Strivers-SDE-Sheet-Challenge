using ll = long long;
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        for(ll i = 0; i<senate.size(); i++){
            if(senate[i] == 'R') r.push(i);
            else d.push(i);
        }
        while(!r.empty() && !d.empty()){
            ll a = r.front();
            ll b = d.front();
            r.pop(); d.pop();
            if(a < b){
                r.push(a + senate.size());
            } else {
                d.push(b + senate.size());
            }
        }
        if(r.empty()){
            return "Dire";
        } else return "Radiant";
    }
};