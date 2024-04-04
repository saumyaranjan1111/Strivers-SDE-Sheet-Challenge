using ll = long long;
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        ll n = nums.size();
        // prev[i] = index of the most recent element which is smaller than nums[i]
        // next[i] = index of the most recent element on the right side which is smaller than nums[i]
        vector<ll> prev(n, -1);
        vector<ll> next(n, n);

        stack<pair<ll, ll>> pre;
        for(ll i = 0; i<n; i++){
            while(!pre.empty() && pre.top().first >= nums[i]){
                pre.pop();
            }

            if(!pre.empty()){
                prev[i] = pre.top().second;
            }
            pre.push({nums[i] , i});
        }

        stack<pair<ll, ll>> nex;
        for(ll i = n-1; i>=0; i--){
            while(!nex.empty() && nex.top().first >= nums[i]){
                nex.pop();
            }

            if(!nex.empty()){
                next[i] = nex.top().second;
            }
            nex.push({nums[i] , i});
        }

        ll ans = 0;
        for(ll i = 0; i<n; i++){
            ll left = prev[i];
            ll right = next[i];
            if(left < k && k < right){
                // valid subarray
                ll score = nums[i] * (right - left - 1);
                ans = max(ans, score);
            }
        }
        return (int)ans;

    }
};