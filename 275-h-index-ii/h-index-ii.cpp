class Solution {
public:
    int hIndex(vector<int>& citations) {
        int hmax = 0;
        int n = citations.size();

        if(n == 1){
            if(citations[0] >= 1) return 1;
            else return 0;
        }

        int low = 0, high = n-1;

        while(low<=high){
            int mid = low + (high - low)/2;
            // can the answer be equal to mid no of papers?
            // only when the value at citations[mid] >= no of papers (ie. n-mid)

            // any value of h can be considered only when there are atleast h papers, all of which have citations >= h, that means that the min of all citations of those h papers should be >= no of papers, so when we check if a mid can be a valid h or not, 
            // we can say that mid is a valid value of h, if all the papers from mid to n-1 all have their values greater than mid, if this is the case then all the papers from mid to n-1 all have been cited at least mid times
            // now we can look for a better h on the left
            // if current mid is not a valid h, then we cant have a h-index as any number >= mid, so we look for smaller lengths and go towards the right

            if(citations[mid] >= n - mid){
                // if possible ans, then look for bigger lengths
                hmax = max(hmax, n - mid);
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return hmax;
    }
};