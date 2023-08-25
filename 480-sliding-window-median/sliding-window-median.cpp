class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<long long> nums2;
        for(auto e: nums) nums2.push_back(e);

        vector<double> ans;
        long long n = nums2.size();
        if(k == 1){
            for(long long i = 0; i<n; i++){
                ans.push_back(nums2[i]);
            }
            return ans;
        }
        map<long long, long long> large, small;

        // large : min heap, small = max heap

        long long s1 = 0, s2 = 0;
        for(long long i = 0; i<k ;i++){
            small[-nums2[i]]++;
            s1++;

            large[-small.begin()->first]++;
            s2++;
            
            if(small.begin() -> second == 1){
                small.erase(small.begin());
            }else {
                small.begin()->second--;
            }

            s1--;

            if(s1 < s2){
                small[-large.begin()->first]++;
                s1++;

                if(large.begin()->second == 1){
                    large.erase(large.begin());
                }else {
                    large.begin()->second--;
                }
                s2--;
            }
        }

        if(s1 == s2){
            ans.push_back((-small.begin()->first + large.begin()->first)/2.0);
        }
        else if(s1 > s2){
            ans.push_back((-small.begin()->first));
        }
        else ans.push_back(large.begin()->first);

        for(long long i = k ; i<n; i++){
            long long remele = nums2[i-k];
            long long addele = nums2[i];
            // check remele is in which half : small or large
            // and remove that element

            if(remele < large.begin()->first){
                // remele is in the first half
                auto it = small.find(-remele);
                if(it->second == 1){
                    small.erase(it);
                } else {
                    it->second--;
                }
                s1--;
            }else {
                // remele is in the second half
                auto it = large.find(remele);
                if(it->second == 1){
                    large.erase(it);
                } else {
                    it->second--;
                }
                s2--;
            }

            // now insert the addele

            small[-addele]++;
            s1++;

            large[-small.begin()->first]++;
            s2++;
            
            if(small.begin() -> second == 1){
                small.erase(small.begin());
            }else {
                small.begin()->second--;
            }

            s1--;

            if(s1 < s2){
                small[-large.begin()->first]++;
                s1++;

                if(large.begin()->second == 1){
                    large.erase(large.begin());
                }else {
                    large.begin()->second--;
                }
                s2--;
            }



            if(s1 == s2){
            ans.push_back((-small.begin()->first + large.begin()->first)/2.0);
            }
            else if(s1 > s2){
                ans.push_back((-small.begin()->first));
            }
            else ans.push_back(large.begin()->first);

        }
        return ans;
    }
};