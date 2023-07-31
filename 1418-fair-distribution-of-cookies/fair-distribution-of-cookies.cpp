class Solution {
public:
    int ans = INT_MAX;
    void solve(int ind, vector<int>& scores, vector<int>& cookies, int currmax){
        if(ind >= cookies.size()){
            ans = min(ans, currmax);
            return;
        }
        int k = scores.size();
        for(int i = 0; i<k; i++){
            // give the current cookie bag to the kth child
            scores[i] += cookies[ind];
            int prevmax = currmax;
            currmax = max(currmax, scores[i]);

            solve(ind + 1, scores, cookies, currmax);

            currmax = prevmax;
            scores[i] -= cookies[ind];
        }


    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> scores(k, 0);
        
        solve(0, scores, cookies, 0);

        return ans;
    }
};