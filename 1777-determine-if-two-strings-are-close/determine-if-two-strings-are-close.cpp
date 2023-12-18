class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if(n!=m) return false;

        map<char, int> mp1, mp2;
        for(auto c:word1) mp1[c]++;
        for(auto c:word2) mp2[c]++;

        if(mp1.size() != mp2.size()) return false;

        for(auto it1 = mp1.begin(), it2 = mp2.begin(); it1!= mp1.end(), it2!= mp2.end(); it1++, it2++){
            if(it1->first != it2->first) return false;
        }

        vector<int> a1, a2;
        for(auto it = mp1.begin(); it!= mp1.end(); it++){
            a1.push_back(it->second);
        }
        for(auto it = mp2.begin(); it!= mp2.end(); it++){
            a2.push_back(it->second);
        }
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        for(int i = 0; i<a1.size(); i++){
            if(a1[i] != a2[i]) return false;
        }

        return true;
    }
};