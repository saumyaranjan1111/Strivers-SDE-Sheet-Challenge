#define ll long long
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        ll sum = 0;
        int n = nums.size();
        for(int i = n-1; i>=0; i--){
            if(nums[i] <= sum) sum+=nums[i];
            else{
                // we found some element which is greater than the current sum we have build, so our new updated answer will be that element
                // sum represents the max element that we are able to build before we come across something which stops us from building a bigger element
                // since we got stopped, the stopper must have been bigger than the element that we have built till now
                // so the new biggest element is the element which stopped us from building the sum even bigger, and we set it to sum
                sum = nums[i];
            }
        }
        return sum;
    }
};