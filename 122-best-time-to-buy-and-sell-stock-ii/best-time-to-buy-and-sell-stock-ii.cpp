class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int ans = 0;
        int i = 0; 
        int j = i+1;
        while( j<n ){

            while( j<n && prices[j] >= prices[j-1]) j++;
            ans+= prices[j-1] - prices[i];
            i = j;
            j = i+1;
        
        }

        return ans;
    }
};