using ll = long long;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<int> ans(n, -1);
        ll ind = k;
        if(2*k + 1 > n){
            return ans;
        } 
        ll sum = 0;
        for(ll i = 0; i<=2*k; i++){
            sum += nums[i];
        }
        ans[ind] = sum/(2*k + 1);

        for(ll l = k; l+k<n-1; l++){
            ind++;
            sum -= nums[l-k];
            sum += nums[l+k+1];

            ans[ind] = sum/(2*k + 1);
        }
        return ans;
    }
};