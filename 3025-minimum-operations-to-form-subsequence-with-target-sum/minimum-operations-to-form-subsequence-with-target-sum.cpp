class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        
        // note : combining two numbers does not have any cost associated with it
        // dividing a no /2 has a cost of 1
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for(auto num:nums) sum+=num;

        if(sum < target) return -1;
        int ans = 0;
        vector<int> bitfreq(32, 0);

        for(auto num : nums){
            int currpow = (int)log2(num);
            bitfreq[currpow]++;
        }

        int minunfulfilledbit = 32;
        for(int i = 0; i<31; i++){
            
            int bit = (1<<i);

            // if the current bit is needed, then the current bit would be set in the target 
            if((bit & target) != 0){
                // this bit is needed in the target

                // if available in the freqarray, take it
                if(bitfreq[i] > 0){
                    // this bit is also available
                    bitfreq[i]--;
                }
                else {
                    // this bit is needed but not yet available in the freq array
                    // this is an unfulfilled position and can be filled by a bigger number later, so we need to store this 
                    minunfulfilledbit = min(minunfulfilledbit, i);
                }
            }
            if( bitfreq[i] > 0 && minunfulfilledbit < i){
                // this bit is not needed and the minunfulfilledbit is somewhere towards the right of the current bit

                // this bit can be used to fulfill the minunfulfilledbit if this is present in the bitfreq array
                    // this bit can be used to fulfill all the bits from i to minunfulfilledbit   
                    // no of operations for fulfill the minunfulfilledbit is equal to the distance of the current bit and the minunfulfilledbit, and doing these no of operations will also fulfill the bits in between, that is why we only keep track of the minunfulfilledbit and not of all the unfulfilled bits in b/w because once we fulfill the minunfulfilledbit, all the bits in the middle will also get fulfilled during the same operations that were used to fulfill the minunfulfilledbit.
                    ans += (i-minunfulfilledbit);
                    bitfreq[i]--;
                    minunfulfilledbit = 32;
            }

            bitfreq[i+1] += bitfreq[i]/2;
            // combine the remaining element at this bit to form a bigger element.
            // if bitfreq[i] = 1, then that means that this number cannot be used to form a bigger power of 2, since there is only 1 left, so automatically bitfreq[i+1] will increase by 0(not increase).
            // if 2 or 3 is left, then 2 of them will be used to make the bigger element, if 4 is left, then 2 of the bigger power will be made by combining all 4

        }
    return ans;
    }
};