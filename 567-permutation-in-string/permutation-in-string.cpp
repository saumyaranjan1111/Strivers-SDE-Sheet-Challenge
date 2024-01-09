#define ll long long
class Solution {
public:
    bool checksets(multiset<char> &s1, multiset<char> &s2){
        if(s1.size() != s2.size()) return false;

        for(auto it = s1.begin(), it2 = s2.begin(); it != s1.end(); it++, it2++){
            if(*it != *it2) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        ll n = s1.size(), m = s2.size();
        if(n > m) return false;
        if(m == n){
            multiset<char> st;
            for(auto c: s1) st.insert(c);

            multiset<char> st2;
            for(auto c: s2) st2.insert(c);
            
            return checksets(st, st2);
        }
        
        // m > n
        // make a window of size n
        map<char, ll> left, right;
        for(auto c: s1){
            left[c]++;
        }

        ll count = 0;
        for(ll i = 0; i<n; i++){
            right[s2[i]]++;
            if(left.find(s2[i]) != left.end() && left.find(s2[i])->second >= right[s2[i]]) count++;
        }

        if(count == n) return true;

        for(ll r = n; r<m; r++){
            right[s2[r]]++;
            if(left.find(s2[r]) != left.end() && left.find(s2[r])->second >= right[s2[r]]) count++;
            
            right[s2[r-n]]--;
            if(left.find(s2[r-n]) != left.end()){
                if(left.find(s2[r-n])->second > right[s2[r-n]]) count--;
            }

            if(right[s2[r-n]] == 0){
                right.erase(s2[r-n]);
            }

            if(count == n) return true;
        }

        return false;
    }
};