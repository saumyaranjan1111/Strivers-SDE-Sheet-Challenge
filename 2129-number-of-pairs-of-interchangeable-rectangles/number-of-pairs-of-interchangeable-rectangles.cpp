class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<double, long long> mp;
        long long count = 0;
        for(int i = 0; i<rectangles.size(); i++){
            double w = rectangles[i][0];
            double h = rectangles[i][1];

            if(mp.find(w/h) != mp.end()){
                count+=mp[w/h];
            }
            mp[w/h]++;
        }
        return count;
    }
};