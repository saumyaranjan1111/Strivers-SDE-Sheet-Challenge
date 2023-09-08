class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        vector<int> &a = citations;
    
        int n = citations.size();

        if(n == 1){
            if(a[0] >= 1) return 1;
            else return 0;
        }
        int hmax = 0;
        for(int i = n-1; i>=0; i--){
            if(n - i >= hmax){
            hmax = max(hmax, min(a[i], n - i));
            }
        }
        return hmax;
    }
};