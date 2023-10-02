class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int andd = nums[0];
        int maxsize = 1;
        int maxtillnow = andd;
        int last = 0;

        for(int i = 1; i<nums.size(); i++){
            if((andd & nums[i]) < andd){
                if(andd >= maxtillnow){
                    maxsize = max(maxsize, i - last);
                    maxtillnow = max(maxtillnow, andd);
                }
                andd = nums[i];
                last = i;

                if(andd > maxtillnow){
                    maxtillnow = max(maxtillnow, andd);
                    maxsize = i - last + 1;
                }
            }
            else {
                
                // if the new element is greater than the current and then reset
                if(nums[i] > andd){

                    // if the current and is greater than all before 
                    // then update the size as well as the maxtillnow
                    if(andd > maxtillnow){
                        maxsize = i - last;
                        maxtillnow = max(maxtillnow, andd);
                    }   
                    // if the current and is == to the previous greatest and
                    // then just update the size after checking if the current size is > the previous size
                    else if(andd == maxtillnow){
                        maxsize = max(maxsize, i - last);
                    }

                    // reset process
                    andd = nums[i];
                    last = i;

                    if(andd > maxtillnow){
                        maxtillnow = max(maxtillnow, andd);
                        maxsize = max(maxsize, i - last + 1);
                    }

                }
                // if the new element is equal to the current and 
                else {
                    
                    // nums[i] == andd
                    // no need to change anything 
                    if(andd > maxtillnow){
                        maxsize = i - last + 1;
                        maxtillnow = andd;
                    }
                    else if(andd == maxtillnow){
                        maxsize = max(maxsize, i - last + 1);
                    }

                }
            }
        }

        return maxsize;
    }
};