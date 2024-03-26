using ll = long long;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        ll n = nums.size();
        ll lasttrue = n-1;
        for(ll i = n-2; i>=0; i--){
            if(lasttrue <= i+nums[i]){
                lasttrue = i;
            }
        }
        return lasttrue <= 0+nums[0] ? true : false;
    }
};