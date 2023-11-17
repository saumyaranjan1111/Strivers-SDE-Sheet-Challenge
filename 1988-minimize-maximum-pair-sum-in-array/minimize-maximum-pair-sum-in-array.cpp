class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // we only needed to sort this so that we could pair up all the smaller elements with the bigger ones 
        // if we just use a frequency map, then all the indices would represent the numbers of the array 
        // and we can just iterate through it once to find all the valid pairs

        int n = nums.size();
        int maxi = INT_MIN;
        int minnum = INT_MAX;
        int maxnum = INT_MIN;

        vector<int> freq(100001, 0);
        // initially the frequency of all the elements is 0, if freq[i] != 0 then that means that the element i is present in the nums array
        for(auto number : nums){
            freq[number]++;
            minnum = min(minnum, number);
            maxnum = max(maxnum, number);
        }

        // now go through the frequency array and check the condition for valid pairs
        int low = 0; int high = 100000;
        while(low<=high){
            // low is not present anymore in the array, either we have paired up all the instances of low in the array, or it did not exist in the original array to begin with, so we will look for the next valid number
            if(freq[low]==0) low++;
            // similarly for high
            if(freq[high]==0) high--;

            if(freq[low] != 0 && freq[high] != 0){
                // we have found a valid pair that exists in the original array
                maxi = max(maxi, low + high);
                freq[low]--;
                freq[high]--;
            }
        }
        return maxi;
    }
};