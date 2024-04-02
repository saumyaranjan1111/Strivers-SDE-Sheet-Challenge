bool comp(pair<int, int> &a, pair<int, int> &b){
    return a.first < b.first;
}
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int>> ps;
        for(int i = 0; i<n; i++){
            ps.push_back({position[i], speed[i]});
        }
        sort(ps.begin(), ps.end(), comp);
        int x = ps[n-1].first;
        int v = ps[n-1].second;

        // time required for the first car to reach the target
        double tm = (double)(target - x)/(double)v;

        int nextx = x;
        int nextv = v;

        int count = 1;

        for(int i = n-2; i>=0; i--){
            int currx = ps[i].first;
            int currv = ps[i].second;
            double treq = (double)(target - currx)/(double)(currv);

            if(treq > tm) {
                count++;
                tm = treq;
            }
            nextx = currx;
            nextv = currv;
        }
        return count;
    }
};