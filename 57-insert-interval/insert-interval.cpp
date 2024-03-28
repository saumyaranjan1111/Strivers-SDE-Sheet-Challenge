class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        vector<vector<int>> ans;
        int i = 0; 
        int n = intervals.size();

        while(i<n && intervals[i][1] < ni[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        while(i<n && intervals[i][0] <= ni[1]){
            ni[0] = min(ni[0], intervals[i][0]);
            ni[1] = max(ni[1], intervals[i][1]);
            i++;
        }
        ans.push_back(ni);

        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};