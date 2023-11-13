class Solution {
    
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        set<char> st;
        for(auto c : vowels){
            st.insert(c);
        }

        vector<char> t(s.size(), '#');
        map<char, int> mp;
        for(int i = 0; i<s.size(); i++){
            char c = s[i];
            if(st.find(c) != st.end()){
                // c is a vowel
                mp[c]++;
            }
            else{
                // c is a consonant
                t[i] = s[i];
            }
        }

        int p = 0;
        while(p<s.size() && t[p]!='#') p++;

        while(!mp.empty()){
            while(p<s.size() && t[p] != '#') p++;
            if(p == s.size()) break;

            t[p] = mp.begin()->first;
            mp.begin()->second--;

            if(mp.begin()->second == 0) mp.erase(mp.begin());
        }

        string ans = "";
        for(auto c : t){
            ans+=c;
        }
        return ans;

    }
};