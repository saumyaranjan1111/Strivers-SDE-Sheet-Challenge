class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // n
        int n = nums.size();
        vector<int> freq(n+1, 0);
        for(auto &x : nums) freq[x]++;

        int rows = 0;
        for(int i = 0; i<=n; i++) rows = max(rows, freq[i]);

        vector<vector<int>> ans(rows);

        int row = 0;

        for(int i = 1; i<=n; i++){
            while(freq[i] > 0){
                ans[row].push_back(i);
                row++;
                row = row%rows;
                freq[i]--;
            }
        }

        return ans;
    }
};