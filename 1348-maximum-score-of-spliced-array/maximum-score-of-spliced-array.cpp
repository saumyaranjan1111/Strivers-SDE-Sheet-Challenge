using ll = long long;
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size();
        ll sum1 = 0, sum2 = 0;
        for(auto x : nums1) sum1+= x;
        for(auto x : nums2) sum2+= x;
        
        vector<ll> delta1(n, 0);
        vector<ll> delta2(n, 0);
        delta1[0] = nums2[0] - nums1[0];
        for(ll i = 1; i<n; i++){
            delta1[i] = delta1[i-1] + (nums2[i] - nums1[i]);
        }

        delta2[0] = nums1[0] - nums2[0];
        for(ll i = 1; i<n; i++){
            delta2[i] = delta2[i-1] + (nums1[i] - nums2[i]);
        }
        // cout<<sum1<<endl;
        // cout<<sum2<<endl;
        // for(auto x : delta) cout<<x<<" ";
        // cout<<endl;
        ll ans1 = 0, ans2 = 0;
        set<ll> minsofar1, minsofar2;
        minsofar1.insert(0);
        minsofar2.insert(0);
        for(auto x : delta1){
            ans1 = max(ans1, x - *minsofar1.begin());
            minsofar1.insert(x);
        }
        for(auto x : delta2){
            ans2 = max(ans2, x - *minsofar2.begin());
            minsofar2.insert(x);
        }

        return max(sum1 + ans1, sum2 + ans2);
    }   
};