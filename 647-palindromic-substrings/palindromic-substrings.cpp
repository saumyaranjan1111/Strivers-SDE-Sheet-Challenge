class Solution {
public:
    int countSubstrings(string s) {
        // expand from middle algo

        int n = s.size();
        int count = 0;

        for(int i = 0; i<n; i++){
            // i is the middle point, and we will find the length of the biggest palindrome that has i as its center

            // now we can have our center in two ways
            // way1: i is the center itself (odd palindrom) : "aba"
            // way2: i,i+1 is the center (even palindrom) : "abba"

            // way1:
            int a = i, b = i;
            while(a>=0 && b<n && s[a] == s[b]) {
                a--;
                b++;
            }
            // b-a+1 is the length of the biggest palindrome of way1 from the center (i, i)
            // ex : xyz has a length of 3, and contains 2 palindromes : xyx and y
            // and r - l for this would be 4, hence count+= (r-l)/2
            // so we increase the count by (r-l)/2

            count+= (b-a)/2;

            a = i, b = i+1;
            while(a>=0 && b<n && s[a] == s[b]){
                a--;
                b++;
            }
            count+= (b-a)/2;
        }
        return count;
    }
};