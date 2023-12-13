class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // index sort : if array is sorted then index i should contain the number i+1
        // for every num that we come across , we will check its final position which will be num - 1, if num - 1 already has num, then we can say that num appears twice in the array
        // if a num does not have another num present in the position num-1, then we swap, so as to make the array sorted upto that point and move forward
        int n = nums.size();

        for(int i = 0; i<n; ){
            int num = nums[i];

            if(num == i+1){
                // num is present at the correct position and we should move on
                i++;              
            }
            else if(nums[num-1] == num){
                // duplicate found
                return num;
            }
            else {
                // neither num is present at its correct position, nor is it the duplicate( currently )
                // put num in its correct position but stay at the same place and check for the new element that we brought in by swapping num to its correct position
                swap(nums[num-1], nums[i]);
            }
        }
        return -1;

    }
};