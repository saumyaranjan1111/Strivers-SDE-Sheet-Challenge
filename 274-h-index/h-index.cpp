class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        int n = citations.size();
        sort(citations.begin(), citations.end(), greater<int>());
        int low = 0;
        int high = n-1;
        int mid;
        // the question we will ask is can mid be a valid h-index, if yes then can it be better than the ones before it
        while(low <= high){
            mid = low + (high - low)/2;
            if(citations[mid] >= mid+1) {
                ans = max(ans, mid+1);
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
};