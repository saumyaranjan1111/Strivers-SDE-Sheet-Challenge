bool comp(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i = 0; 
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        while(i<n){
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(i<n && intervals[i][0] <= end){
                end = max(end, intervals[i][1]);
                i++;
            }

            ans.push_back({start, end});
        }
        return ans;
    }
};