class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0; 
        int j = 0;
        int n = s.size();
        map<char, int> mp;

        int count = 0;

        while(j < s.size()){
            // expand window until mp size becomes 3
            while(j < s.size() && mp.size() < 3){
                mp[s[j]]++;
                j++;
            }

            if(mp.size() == 3)
            count += n - j + 1;

            while(mp.size() == 3){
                mp[s[i]]--;
                if(mp[s[i]] <= 0) mp.erase(s[i]);

                if(mp.size() == 3){
                    count += n - j + 1;
                }

                i++;
            }

        }

        return count;
    }
};