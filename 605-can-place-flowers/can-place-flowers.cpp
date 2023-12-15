class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int count = 0;
        int sz = f.size();
        if(n==0) return true;
        if(sz == 1 ){
            return !f[0];
        }
        if(sz >= 2){
            if(f[0] == 0 && f[1] == 0){
                count++;
                f[0] = 1;
            }
            if(f[sz-1] == 0 && f[sz-2] == 0){
                count++;
                f[sz-1] = 1;
            }
        }

        for(int i = 1; i<sz-1; i++){
            if(f[i] == 0 && f[i-1] == 0 && f[i+1] == 0){
                count++;
                f[i] = 1;
            }
        }

        return count>=n;
    }
};