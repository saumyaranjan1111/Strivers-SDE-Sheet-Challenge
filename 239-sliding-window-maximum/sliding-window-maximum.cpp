class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        for(int i = 0; i<k; i++){
            while(!dq.empty() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());

        int r = k;
        while(r<n){
            if(dq.front() == nums[r - k]) dq.pop_front();
            while(!dq.empty() && dq.back() < nums[r]) dq.pop_back();
            dq.push_back(nums[r]);
            ans.push_back(dq.front());
            r++;
        }

        return ans;
    }
};