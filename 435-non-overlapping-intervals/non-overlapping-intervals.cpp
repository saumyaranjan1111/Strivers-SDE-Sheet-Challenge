bool comp(vector<int>&a, vector<int>&b){
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int count = 0;
        int n = intervals.size();
        
        int end = intervals[0][1];
        for(int i = 1; i<n; i++){
            int newst = intervals[i][0];
            int newend = intervals[i][1];
            
            if(newst < end){
                count++;
            } else {
                end = max(end, newend);
            }
        }
        return count;
    }
};