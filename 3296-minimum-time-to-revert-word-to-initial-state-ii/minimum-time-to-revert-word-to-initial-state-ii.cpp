class Solution {
public:
    vector<int> z_function(string &s) {
        int n = s.size();
        vector<int> z(n);
        z[0] = n;
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i <= r)
                z[i] = min(z[i - l], r - i + 1);
            for (int &j = z[i]; i + j < n && s[j] == s[i + j]; j++);
            if (z[i] > r - i + 1)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }
    int minimumTimeToInitialState(string word, int k) {
        int n= word.size();
        
        vector<int> z = z_function(word);
        
        if(n == k){
            return 1;
        }
        int final = 0;
        for(int i = k; i<n; i+=k){
            if(z[i] == n - i){
                final = i;
                break;
            }
            if(i + k >= n){
                final = i+k;
            }
        }
        
        return final/k;
    }
};