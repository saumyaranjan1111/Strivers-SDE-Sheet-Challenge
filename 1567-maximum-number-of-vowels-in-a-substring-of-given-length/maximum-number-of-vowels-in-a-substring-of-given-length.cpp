class Solution {

public:
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    bool isvowel(char c){
        for(auto ch : vowels){
            if(ch == c) return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int curr = 0;
        int maxi = 0;

        for(int i =0; i<k; i++){
            if(isvowel(s[i])) curr++;
        }

        maxi = max(maxi, curr);

        int l = 0, r = k;
        int n = s.size();
        for(; r<n; r++, l++){
            if(isvowel(s[l])) curr--;
            if(isvowel(s[r])) curr++;

            maxi = max(maxi, curr);
        }

        return maxi;
    }
};