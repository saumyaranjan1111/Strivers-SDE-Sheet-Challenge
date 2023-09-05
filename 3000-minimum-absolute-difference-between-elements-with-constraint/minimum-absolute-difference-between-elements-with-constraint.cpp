class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        
        int n = nums.size();
        if(n < x || x == 0) return 0;
        if(x == n-1){
            return abs(max(nums[0], nums[n-1]) - min(nums[0], nums[n-1]));
        }
        if(n == 1) return nums[0];
        if(n == 2) return abs(max(nums[0], nums[1]) - min(nums[0], nums[1]));
        
        long long ans = INT_MAX;
        // int maxi = INT_MIN;
        // int mini = INT_MAX;
        // for(auto e: nums){
        //     maxi = max(maxi, e);
        //     mini = min(mini, e);
        // }
        // ans = abs(maxi-mini);
        
        set<int> st;
//         set will contain the elements that are atleast k or more indices back from the current element
        
        
//         now at this point we will try to look back in the set and try to find the value that is in the set that is the closest to the current element, can do this using lower_bound and upper_bound
        for(int l = 0, i = x; i<n; i++, l++){
            st.insert(nums[l]);
            
            int currele = nums[i];
//             look for the closest number to currele in the set
            auto it = st.upper_bound(currele);
//             lower_bound returns the first value >= x
            
            if(it != st.end()){
//                 there exists a no >x in the set
                ans = min(ans, (long long)abs(*it - currele));
            }
            if(it != st.begin()){
                it--; 
                ans = min(ans, (long long)abs(currele - *it));    
            }
        }
        
        return (int)ans;
    }
};