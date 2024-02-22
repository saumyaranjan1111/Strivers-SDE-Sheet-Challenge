using ll = long long;
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> og;
        for(auto x : senate) og.push(x);

        queue<char> q;
        while(!og.empty()){
            char x = og.front();
            og.pop();
            if(q.empty() || q.front() == x){
                q.push(x);
            } else {
                og.push(q.front());
                q.pop();
            }
        }

        if(q.front() == 'D'){
            return "Dire";
        } else return "Radiant";
    }
};